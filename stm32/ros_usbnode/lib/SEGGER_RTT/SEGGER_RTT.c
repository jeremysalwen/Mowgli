/* Minimal SEGGER-RTT-compatible up-channel. See SEGGER_RTT.h for rationale. */
#include "SEGGER_RTT.h"
#include <string.h>

#define BUFFER_SIZE_UP 4096u

/* Up-buffer descriptor - field order/types must match what OpenOCD's RTT
 * reader expects (sName, pBuffer, SizeOfBuffer, WrOff, RdOff, Flags). */
typedef struct
{
  const char       *sName;
  char             *pBuffer;
  unsigned          SizeOfBuffer;
  unsigned          WrOff; /* next write position - written by target */
  volatile unsigned RdOff; /* next read position  - written by host   */
  unsigned          Flags;
} SEGGER_RTT_BUFFER_UP;

typedef struct
{
  char                 acID[16];
  int                  MaxNumUpBuffers;
  int                  MaxNumDownBuffers;
  SEGGER_RTT_BUFFER_UP aUp[1];
} SEGGER_RTT_CB;

static char _acUpBuffer[BUFFER_SIZE_UP];

/* Control block - statically initialized so the "SEGGER RTT" ID is present in
 * RAM immediately after C startup, making it discoverable by a memory search.
 * Must keep external linkage so it is not optimized away. */
SEGGER_RTT_CB _SEGGER_RTT = {
    "SEGGER RTT\0\0\0\0\0",
    1,
    0,
    {{"Terminal", _acUpBuffer, BUFFER_SIZE_UP, 0, 0, 0}},
};

unsigned SEGGER_RTT_Write(unsigned BufferIndex, const void *pBuffer, unsigned NumBytes)
{
  (void)BufferIndex; /* only channel 0 supported */
  const char *p = (const char *)pBuffer;
  SEGGER_RTT_BUFFER_UP *pRing = &_SEGGER_RTT.aUp[0];
  unsigned WrOff = pRing->WrOff;
  unsigned written = 0;

  while (NumBytes--)
  {
    unsigned NextWrOff = WrOff + 1u;
    if (NextWrOff >= BUFFER_SIZE_UP)
    {
      NextWrOff = 0u;
    }
    if (NextWrOff == pRing->RdOff)
    {
      break; /* full: drop remainder (NoBlockSkip), never stall the caller */
    }
    _acUpBuffer[WrOff] = *p++;
    WrOff = NextWrOff;
    written++;
  }
  pRing->WrOff = WrOff; /* publish only after the bytes are in the buffer */
  return written;
}

unsigned SEGGER_RTT_WriteString(unsigned BufferIndex, const char *s)
{
  return SEGGER_RTT_Write(BufferIndex, s, (unsigned)strlen(s));
}
