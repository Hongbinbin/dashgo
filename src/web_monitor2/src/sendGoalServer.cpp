#include <ros/ros.h>
#include "web_monitor2/sendGoalPose.h"
#include <geometry_msgs/Pose.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

bool sendMoveBase(web_monitor2::sendGoalPose::Request &req, web_monitor2::sendGoalPose::Response &res)
{
  ROS_INFO("Pose.position:\n x:%f\n y:%f\n z:%f", req.pose.position.x, req.pose.position.y, req.pose.position.z);
  ROS_INFO("Pose.orientation:\n x:%f\n y:%f\n z:%f\n w:%f", req.pose.orientation.x, req.pose.orientation.y, req.pose.orientation.z, req.pose.orientation.w);
  MoveBaseClient ac("move_base", true);
  while (!ac.waitForServer(ros::Duration(5.0)))
  {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  move_base_msgs::MoveBaseGoal goal;

  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose = req.pose;
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("The meidum_point goal is reached");
    res.status = 1;
  }
  else
  {
    ROS_INFO("Can't move to seat goal for some reason!!");
    res.status = 0;
  }
  res.status = 1;
  ROS_INFO("sending back response: [%ld]",(long int) res.status);
  return true;
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "sendGoalPose_server");
  
  ROS_INFO("start sendGoalPose service");
  ros::NodeHandle nh;
  ros::ServiceServer service = nh.advertiseService("sendGoalPoseFromJS", sendMoveBase);
  ROS_INFO("Ready to get the Goal Pose.");
  ros::spin();
  while (!ros::ok())
  {
    ros::shutdown();
  }

  return 0;
}
