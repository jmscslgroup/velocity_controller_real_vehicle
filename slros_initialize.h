#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block velocity_controller_real_vehicle/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_velocity_controller_real_vehicle_geometry_msgs_Twist> Sub_velocity_controller_real_vehicle_10;

// For Block velocity_controller_real_vehicle/relative velocity
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_velocity_controller_real_vehicle_geometry_msgs_Twist> Sub_velocity_controller_real_vehicle_34;

// For Block velocity_controller_real_vehicle/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_velocity_controller_real_vehicle_std_msgs_Float64> Pub_velocity_controller_real_vehicle_3;

void slros_node_init(int argc, char** argv);

#endif
