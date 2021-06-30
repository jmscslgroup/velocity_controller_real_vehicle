#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "velocity_controller_real_vehicle";

// For Block velocity_controller_real_vehicle/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_velocity_controller_real_vehicle_geometry_msgs_Twist> Sub_velocity_controller_real_vehicle_10;

// For Block velocity_controller_real_vehicle/relative velocity
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_velocity_controller_real_vehicle_geometry_msgs_Twist> Sub_velocity_controller_real_vehicle_34;

// For Block velocity_controller_real_vehicle/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_velocity_controller_real_vehicle_std_msgs_Float64> Pub_velocity_controller_real_vehicle_3;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

