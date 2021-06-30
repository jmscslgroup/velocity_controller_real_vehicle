#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Float64.h>
#include "velocity_controller_real_vehicle_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_velocity_controller_real_vehicle_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_velocity_controller_real_vehicle_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_velocity_controller_real__Vector3_qiepqm const* busPtr);
void convertToBus(SL_Bus_velocity_controller_real__Vector3_qiepqm* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(std_msgs::Float64* msgPtr, SL_Bus_velocity_controller_real_vehicle_std_msgs_Float64 const* busPtr);
void convertToBus(SL_Bus_velocity_controller_real_vehicle_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);


#endif
