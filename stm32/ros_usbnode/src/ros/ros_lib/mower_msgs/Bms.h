#ifndef _ROS_mower_msgs_Bms_h
#define _ROS_mower_msgs_Bms_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace mower_msgs
{

  class Bms : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _current_type;
      _current_type current;
      typedef float _relative_state_of_charge_type;
      _relative_state_of_charge_type relative_state_of_charge;
      typedef float _remaining_capacity_type;
      _remaining_capacity_type remaining_capacity;
      typedef float _full_charge_capacity_type;
      _full_charge_capacity_type full_charge_capacity;
      typedef uint16_t _cycle_count_type;
      _cycle_count_type cycle_count;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef const char* _battery_status_type;
      _battery_status_type battery_status;
      typedef const char* _extra_data_type;
      _extra_data_type extra_data;

    Bms():
      stamp(),
      voltage(0),
      current(0),
      relative_state_of_charge(0),
      remaining_capacity(0),
      full_charge_capacity(0),
      cycle_count(0),
      temperature(0),
      battery_status(""),
      extra_data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_relative_state_of_charge;
      u_relative_state_of_charge.real = this->relative_state_of_charge;
      *(outbuffer + offset + 0) = (u_relative_state_of_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_state_of_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_state_of_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_state_of_charge.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_state_of_charge);
      union {
        float real;
        uint32_t base;
      } u_remaining_capacity;
      u_remaining_capacity.real = this->remaining_capacity;
      *(outbuffer + offset + 0) = (u_remaining_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remaining_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remaining_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remaining_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remaining_capacity);
      union {
        float real;
        uint32_t base;
      } u_full_charge_capacity;
      u_full_charge_capacity.real = this->full_charge_capacity;
      *(outbuffer + offset + 0) = (u_full_charge_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_full_charge_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_full_charge_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_full_charge_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->full_charge_capacity);
      *(outbuffer + offset + 0) = (this->cycle_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cycle_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cycle_count);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      uint32_t length_battery_status = strlen(this->battery_status);
      varToArr(outbuffer + offset, length_battery_status);
      offset += 4;
      memcpy(outbuffer + offset, this->battery_status, length_battery_status);
      offset += length_battery_status;
      uint32_t length_extra_data = strlen(this->extra_data);
      varToArr(outbuffer + offset, length_extra_data);
      offset += 4;
      memcpy(outbuffer + offset, this->extra_data, length_extra_data);
      offset += length_extra_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_relative_state_of_charge;
      u_relative_state_of_charge.base = 0;
      u_relative_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_state_of_charge = u_relative_state_of_charge.real;
      offset += sizeof(this->relative_state_of_charge);
      union {
        float real;
        uint32_t base;
      } u_remaining_capacity;
      u_remaining_capacity.base = 0;
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->remaining_capacity = u_remaining_capacity.real;
      offset += sizeof(this->remaining_capacity);
      union {
        float real;
        uint32_t base;
      } u_full_charge_capacity;
      u_full_charge_capacity.base = 0;
      u_full_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_full_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_full_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_full_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->full_charge_capacity = u_full_charge_capacity.real;
      offset += sizeof(this->full_charge_capacity);
      this->cycle_count =  ((uint16_t) (*(inbuffer + offset)));
      this->cycle_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->cycle_count);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      uint32_t length_battery_status;
      arrToVar(length_battery_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_battery_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_battery_status-1]=0;
      this->battery_status = (char *)(inbuffer + offset-1);
      offset += length_battery_status;
      uint32_t length_extra_data;
      arrToVar(length_extra_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_extra_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_extra_data-1]=0;
      this->extra_data = (char *)(inbuffer + offset-1);
      offset += length_extra_data;
     return offset;
    }

    virtual const char * getType() override { return "mower_msgs/Bms"; };
    virtual const char * getMD5() override { return "badda920da1cbd8d7643d8eeed80614e"; };

  };

}
#endif
