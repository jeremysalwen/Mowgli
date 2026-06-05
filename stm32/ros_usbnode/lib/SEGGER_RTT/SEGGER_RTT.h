/*
 * Minimal SEGGER-RTT-compatible logging over SWD.
 *
 * Implements just enough of the SEGGER RTT control-block layout for OpenOCD's
 * `rtt` commands (and any RTT viewer) to discover the block and read the
 * up-channel. Single up-buffer, no down-buffer. Non-blocking "skip" mode: if
 * no host is draining the buffer, new bytes are dropped rather than stalling
 * the caller - safe to call from time-critical firmware paths.
 *
 * Why RTT on this board: PB3 (TRACESWO) is repurposed by SW_I2C_Init() for the
 * J18 soft-I2C IMU, so real SWO output is impossible. RTT rides the existing
 * SWDIO/SWCLK lines instead, needing no extra pin.
 */
#ifndef SEGGER_RTT_H
#define SEGGER_RTT_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned SEGGER_RTT_Write(unsigned BufferIndex, const void *pBuffer, unsigned NumBytes);
unsigned SEGGER_RTT_WriteString(unsigned BufferIndex, const char *s);

#ifdef __cplusplus
}
#endif

#endif /* SEGGER_RTT_H */
