#include "ros/ros.h"
//#include "web_monitor/sendGoalPose.h"
#include <cstdlib>
#include "geometry_msgs/Pose.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sendGoalPose_client");
    

    ros::NodeHandle n;
    /*ros::ServiceClient client = n.serviceClient<web_monitor::sendGoalPose>("sendGoalPose");
    
    web_monitor::sendGoalPose srv;
    geometry_msgs::Pose  test;
    test.position.x=1;
    test.position.y=2; 
    test.position.z=3;
    test.orientation.x=4;
    test.orientation.y=5;
    test.orientation.z=6;
    test.orientation.w=7;

    srv.request.pose=test;

    if (client.call(srv))
    {
        ROS_INFO("Status: %d", srv.response.status);
    }
    else
    {
        ROS_ERROR("Failed to call service sendGoalPose");
        return 1;
    }
	*/
    return 0;
}
