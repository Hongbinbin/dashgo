// Basic include
#include <ros/ros.h>
#include <string>
// OMNI 6 include 
#include "neo_msgs/EndPose.h"
#include "neo_msgs/JointAngles.h"
#include "neo_msgs/JointCurrent.h"
#include "neo_msgs/JointVelocity.h"
#include "neo_msgs/SetEOATAction.h"
#include "neo_msgs/MoveToPose.h"
#include "neo_msgs/MoveToAngles.h"
// N1 include
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <iostream>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include "stdlib.h"
#include "std_msgs/Int32.h"

// Initial definitions
#define GOHOME "HOME"
#define GOHOME_2 "HOME2"
#define Cafe_GOHOME "CAFE_HOME"
#define GOGOAL1 "GOAL1"
#define GOGOAL2 "GOAL2"
#define GOGOAL3 "GOAL3"
#define GOGOAL4 "GOAL4"
#define TAKEMEAL "TAKE"

// Single points only(335)
#define GOAL1_1 "GOAL1_1"
#define GOAL1_2 "GOAL1_2"
#define GOAL2_1 "GOAL2_1"
#define GOAL2_2 "GOAL2_2"
// Single points only(cafe)
#define Cafe_GOAL1 "CAFE_GOAL1"
#define Cafe_GOAL2 "CAFE_GOAL2"
#define Cafe_GOAL3 "CAFE_GOAL3"
#define Cafe_GOAL4 "CAFE_GOAL4"
#define Cafe_GOAL5 "CAFE_GOAL5"
#define Cafe_GOAL6 "CAFE_GOAL6"
#define Cafe_GOAL7 "CAFE_GOAL7"
#define Cafe_GOAL8 "CAFE_GOAL8"
#define Cafe_GOAL9 "CAFE_GOAL9"
#define Cafe_GOAL10 "CAFE_GOAL10"
#define Cafe_GOAL11 "CAFE_GOAL11"
#define Cafe_GOAL12 "CAFE_GOAL12"
#define Cafe_GOAL13_14 "CAFE_GOAL13_14"
#define Cafe_GOAL15_16 "CAFE_GOAL15_16"

// Collect the meal(335)
#define COLLECT_FROM_GOAL_1_1 "COLLECT_FROM_GOAL_1_1"
#define COLLECT_FROM_GOAL_1_2 "COLLECT_FROM_GOAL_1_2"
#define COLLECT_FROM_GOAL_2_1 "COLLECT_FROM_GOAL_2_1"
#define COLLECT_FROM_GOAL_2_2 "COLLECT_FROM_GOAL_2_2"
// Collect the meal(cafe)
#define COLLECT_FROM_GOAL1_CAFE "COLLECT_FROM_GOAL1_CAFE"
#define COLLECT_FROM_GOAL2_CAFE "COLLECT_FROM_GOAL2_CAFE"
#define COLLECT_FROM_GOAL3_CAFE "COLLECT_FROM_GOAL3_CAFE"
#define COLLECT_FROM_GOAL4_CAFE "COLLECT_FROM_GOAL4_CAFE"

// Take the meal(335)
#define TAKE_TO_GOAL_1_1 "TAKE_TO_GOAL_1_1"
#define TAKE_TO_GOAL_1_2 "TAKE_TO_GOAL_1_2"
#define TAKE_TO_GOAL_2_1 "TAKE_TO_GOAL_2_1"
#define TAKE_TO_GOAL_2_2 "TAKE_TO_GOAL_2_2"
// Take the meal(cafe)
#define TAKE_TO_GOAL1_CAFE "TAKE_TO_CAFE1"
#define TAKE_TO_GOAL2_CAFE "TAKE_TO_CAFE2"
#define TAKE_TO_GOAL3_CAFE "TAKE_TO_CAFE3"
#define TAKE_TO_GOAL4_CAFE "TAKE_TO_CAFE4"
#define TAKE_TO_GOAL5_CAFE "TAKE_TO_CAFE5"
#define TAKE_TO_GOAL6_CAFE "TAKE_TO_CAFE6"
#define TAKE_TO_GOAL7_CAFE "TAKE_TO_CAFE7"
#define TAKE_TO_GOAL8_CAFE "TAKE_TO_CAFE8"
#define TAKE_TO_GOAL9_CAFE "TAKE_TO_CAFE9"
#define TAKE_TO_GOAL10_CAFE "TAKE_TO_CAFE10"
#define TAKE_TO_GOAL11_CAFE "TAKE_TO_CAFE11"
#define TAKE_TO_GOAL12_CAFE "TAKE_TO_CAFE12"
#define TAKE_TO_GOAL13_14_CAFE "TAKE_TO_CAFE13_14"
#define TAKE_TO_GOAL15_16_CAFE "TAKE_TO_CAFE15_16"
//20191025(update)
#define TAKE_TO_GOAL1_CAFE_new "TAKE_TO_CAFE1_NEW" // TAKE
#define TAKE_TO_GOAL2_CAFE_new "TAKE_TO_CAFE2_NEW"
#define TAKE_TO_GOAL3_CAFE_new "TAKE_TO_CAFE3_NEW"
#define TAKE_TO_GOAL6_CAFE_new "TAKE_TO_CAFE6_NEW"
#define TAKE_TO_GOAL7_CAFE_new "TAKE_TO_CAFE7_NEW"
#define TAKE_TO_GOAL8_CAFE_new "TAKE_TO_CAFE8_NEW"
#define COLLECT_TO_GOAL1_CAFE_new "COLLECT_TO_CAFE1_NEW" // COLLECT
#define COLLECT_TO_GOAL2_CAFE_new "COLLECT_TO_CAFE2_NEW"
#define COLLECT_TO_GOAL3_CAFE_new "COLLECT_TO_CAFE3_NEW"
#define COLLECT_TO_GOAL6_CAFE_new "COLLECT_TO_CAFE6_NEW"
#define COLLECT_TO_GOAL7_CAFE_new "COLLECT_TO_CAFE7_NEW"
#define COLLECT_TO_GOAL8_CAFE_new "COLLECT_TO_CAFE8_NEW"
//20200304(TEST)
#define TEST "TEST"
 
using namespace std;

// START For N1
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

bool Callback_flag = false,WAIT = true;
string arrive_position = "";
string msg_str = "";
int return_put_down_num = 0;


typedef struct _POSE
{
  double X;
  double Y;
  double Z;
  double or_x;
  double or_y;
  double or_z;
  double or_w;
} POSE;

typedef struct Neo_POSE
{
  string Step_Name;
  double X;
  double Y;
  double Z;
  double Rx;
  double Ry;
  double Rz;
} Neo_POSE;

typedef struct Gripper_POSE
{
  string NAME;
  string ACTION;
} Gripper_POSE;
// END For N1

// Set coordinates of the space for N1
POSE home = {0.155291183046, 0.0224557849882, 0.138, 0.0, 0.0, 0.0023300333415, 0.999997285469};
// POSE home2 = {0.198950537479, -0.0506683966777, 0.138, 0.0, 0.0, 0.0145251092119, 0.999894505037};
POSE home2 = {0.136499346146, 0.0263122121675, 0.138, 0.0, 0.0, -9.27490156775e-05, 0.999999995699};
POSE cafe_home = {0.118654382384,-0.0411183002453,0.138,0.0,0.0,0.000366078484082,0.999999932993};
//POSE cafe_return = {-2.39755218865,-2.87348045331,0.138,0.0,0.0,-0.710309119838,0.703889873684};
POSE cafe_return = {-2.38796829579,-3.03769708164,0.138,0.0,0.0,-0.698991948718,0.715129537655};
/* FOR TEST */
POSE goal1 = {-4.41606271919,-2.73003999551,0.138,0.0,0.0,-0.724657271042,0.689109453952};
POSE goal2 = {-8.08191006445,-2.97538740676,0.138,0.0,0.0,-0.691347412486,0.722522494632};
POSE goal3 = {-11.1936213995,-3.19061956325,0.138,0.0,0.0,-0.707796518655,0.706416370266};
POSE goal4 = {-16.0515149433,-3.61703005424,0.138,0.0,0.0,-0.703486143435,0.71070897419};
POSE goal5 = {-20.2864545964,-4.03298410652,0.138,0.0,0.0,-0.702447198243,0.711735859487};
POSE goal6 = {-5.2988635179,-1.61297216198,0.138,0.0,0.0,0.928304228585,0.371821542128};
POSE goal7 = {-7.62897809543,-1.90674807786,0.138,0.0,0.0,0.944313405907,0.329047399966};
POSE goal8 = {-10.1814037761,-2.09036851197,0.138,0.0,0.0,0.937921306399,0.346848126709};
//POSE goal9 = {};
//POSE goal10 = {};
POSE goal11 = {-15.0130781387,1.71882724506,0.138,0.0,0.0,0.729565642589,0.683910793271};
POSE goal12 = {-17.6839149979,1.60176682076,0.138,0.0,0.0,0.733193309798,0.6800202721};
POSE goal13_14 = {-14.9711878317,0.138,-1.44926653747,0.0,0.0,0.998935143264,-0.0461365316429};
POSE goal15_16 = {-17.9433063092,-1.70792909336,0.138,0.0,0.0,-0.0284032134743,0.999596547345};

/* My goals for use */
POSE goal1_1 = {-1.95041619662, -1.67914130716, 0.138, 0.0, 0.0, -0.630874536165, 0.775884862346};
POSE goal1_2 = {-1.23942170791, -2.28984167099, 0.138, 0.0, 0.0, 0.999965090489, 0.00835570486025};
POSE goal2_1 = {-3.87707724345, 1.06660806001, 0.138, 0.0, 0.0, 0.69997039453, 0.714171860816};
POSE goal2_2 = {-3.30805927756, 1.60481908878, 0.138, 0.0, 0.0, 0.994780727248, -0.102035801049};
//cafe goal//

POSE cafe_goal2_tmp = {-5.7895559178,-2.48122913314,0.138,0.0,0.0,0.999960525932,0.00888518863566};
//
POSE cafe_goal1 = {-4.35421625716,-2.81790484598,0.138,0.0,0.0,-0.736887560433,0.676015327695};
//POSE cafe_goal2 = {-7.98738352287,-3.09813347853,0.138,0.0,0.0,-0.705762793743,0.708448218975};
POSE cafe_goal2 = {-8.00296827605,-3.0621016524,0.138,0.0,0.0,-0.686781549549,0.726863882167};
//POSE cafe_goal3 = {-11.0886889318,-3.32163581555,0.138,0.0,0.0,-0.712536166327,0.701635383712};
//POSE cafe_goal3 = {-11.3042435464,-3.23472763316,0.138,0.0,0.0,-0.711312875387,0.702875517648}; // the secend set 20200630
POSE cafe_goal3 = {-10.939310506,-3.30876263208,0.138,0.0,0.0,-0.696984782383,0.717085917535};
POSE cafe_goal4 = {-16.1293238411,-3.55640946793,0.138,0.0,0.0,-0.694492580972,0.719499864471};
POSE cafe_goal5 = {-20.3083618957,-3.9524369852,0.138,0.0,0.0,-0.685903126324,0.727692861926};
//POSE cafe_goal6 = {-5.24901495544,-1.67738481655,0.138,0.0,0.0,0.939533108741,0.342458081492};
POSE cafe_goal6 = {-5.22246566356,-1.69937393479,0.138,0.0,0.0,0.929088786536,0.369856765159};
//POSE cafe_goal7 = {-7.64543524725,-1.88974824019,0.138,0.0,0.0,0.935609816745,0.353035792534};
//POSE cafe_goal7 = {-7.77800626409,-1.76500691119,0.138,0.0,0.0,0.951572052493,0.307425810422};
POSE cafe_goal7 = {-7.71132030294,-1.79189637086,0.138,0.0,0.0,0.965348923962,0.260962554794};
//POSE cafe_goal8 = {-10.3154500322,-2.00451021095,0.138,0.0,0.0,0.935648898616,0.352932201022};
POSE cafe_goal8 = {-10.3676812989,-1.98475461587,0.138,0.0,0.0,0.952363828596,0.30496415852};
//POSE cafe_goal9 = {};
//POSE cafe_goal10 = {};
POSE cafe_goal11 = {-14.9254135643,1.6594570927,0.138,0.0,0.0,0.751367267892,0.659884254048};
//POSE cafe_goal12 = {-17.6839149979,1.60176682076,0.138,0.0,0.0,0.733193309798,0.6800202721};
POSE cafe_goal12 = {-7.89330099665,-2.96148218595,0.138,0.0,0.0,-0.695565621593,0.71846257109};
POSE cafe_goal13_14 = {-14.9711878317,0.138,-1.44926653747,0.0,0.0,0.998935143264,-0.0461365316429};
POSE cafe_goal15_16 = {-17.9433063092,-1.70792909336,0.138,0.0,0.0,-0.0284032134743,0.999596547345};
// goal buffer
//POSE cafe_return_tmp = {-2.82782568839,-1.04015683654,0.138,0.0,0.0,0.968410339579,-0.24936201434};
POSE cafe_return_tmp = {-2.34478257838,-1.13052331952,0.138,0.0,0.0,-0.00877921562513,0.999961461944};
POSE buffer1_6 = {-4.46661906158,-2.14450084367,0.138,0.0,0.0,0.974307169272,-0.225223311192};
POSE cafe_goal2_1 = {-8.15242720107,-2.59820052444,0.138,0.0,0.0,0.99947761372,-0.0323187201636};
POSE cafe_goal3_1 = {-11.2293635161,-2.75242947436,0.138,0.0,0.0,0.998576417214,-0.0533398442404};
POSE front_buffer1_2_6_7 = {-6.16480891115,-2.7689569541,0.138,0.0,0.0,0.999815843786,0.0191905840309};
POSE back_buffer1_2_6_7_tmp1 = {-7.08264644359,-2.84681185585,0.138,0.0,0.0,0.0759786098534,0.997109447776};
POSE back_buffer1_2_6_7_tmp2 = {-5.69446758841,-2.85190612304,0.138,0.0,0.0,0.199956948352,0.979804684009};
POSE back_buffer2_3_7_8_tmp1 = {-10.4183086915,-2.92418959025,0.138,0.0,0.0,0.274086907424,0.961704927293};
POSE buffer2_7 = {-7.54233847148,-2.39506317727,0.138,0.0,0.0,0.983979263768,-0.178282944988};
POSE buffer3_8 = {-9.64148034765,-2.68815874239,0.138,0.0,0.0,0.999682351207,-0.0252031086255};
POSE buffer5 = {-20.3298045473,-3.84643530066,0.138,0.0,0.0,-0.672290990962,0.740286987236};

// Neo step-by-step Pose
Neo_POSE ready_pose = {"Position 1 arrived. READY POSE .\n",193.585587,0.000000,628.970276,-180.000000,-0.004126,0.000000}; //[Pose 1 - READY POSE] : move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
Neo_POSE move_forward = {"Position 2 arrived. MOVE FORWARD .\n",486.282745,-0.022378,612.246338,-180.000000,0.999381,0.002637};//[Pose 2 - MOVE FORWARD] : move_to_angles [1,2,3,4,5,6] [0,27,34,0,28,0] 10 60 0 0
Neo_POSE take_it_up = {"Position 3 arrived. TAKE IT UP .\n",388.897675,0.040268,661.666809,-180.000000,-1.000320,-0.005933};//[Pose 3 - TAKE IT UP] : move_to_angles [1,2,3,4,5,6] [0,10,45,0,36,0] 10 60 0 0
Neo_POSE go_back_to_ready_pose = {"Position 4 arrived. READY POSE .\n",178.113083,0.001366,650.828857,-180.000000,1.003477,-0.000439};//[Pose 4 - Go back to READY POSE] : move_to_angles [1,2,3,4,5,6] [0,-30,80,0,39,0] 10 60 0 0
Neo_POSE fold = {"Position 5 arrived. FOLD .\n",-113.988853,0.000000,488.099701,-180.000000,-2.003237,0.000000};//[Pose 5 - FOLD] : move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
Neo_POSE take_ready_pose = {"Position 6 arrived. READY POSE\n",156.767258,0.000000,633.711914,-180.000000,-0.995609,0.000000};//[Pose 6 - TAKE READY POSE] : move_to_angles [1,2,3,4,5,6] [0,-35,85,0,41,0] 10 60 0 0
Neo_POSE take_move_forward1 = {"Position 7 arrived. MOVE FORWARD1\n",121.020477,0.000000,669.453735,-180.000000,-0.995788,0.000000};//[Pose 7-1 -TAKE MOVE FORWARD1] : move_to_angles [1,2,3,4,5,6] [0,-35,75,0,51,0] 10 60 0 0
Neo_POSE take_move_forward2 = {"Position 7 arrived. MOVE FORWARD2\n",475.873169,0.045624,627.833740,-180.000000,-0.000778,-0.005493};//[Pose 7-2 - Put it down briefly on customers' table] : move_to_angles [1,2,3,4,5,6] [0,27,30,0,33,0] 10 60 0 0
Neo_POSE take_move_forward3 = {"Position 7 arrived. MOVE FORWARD3\n",373.485321,0.000000,598.933472,-180.000000,-0.998206,0.000000};//[Pose 7-3 ] : move_to_angles [1,2,3,4,5,6] [0,0,70,0,21,0] 10 60 0 0
Neo_POSE take_move_forward4 = {"Position 7 arrived. MOVE FORWARD4\n",376.806244,0.000000,589.336853,-180.000000,-1.002485,0.000000};//[Pose 7-4 ] : move_to_angles [1,2,3,4,5,6] [0,0,72,0,19,0] 10 60 0 0
// 20191025(update)
Neo_POSE move_forward_new1 = {"Position arrived. READY POSE .\n",154.557510,-116.467339,628.997498,-180.000000,0.003926,36.999977};//move_to_angles [1,2,3,4,5,6] [-37,-30,85,0,35,0] 10 60 0 0
Neo_POSE move_forward_new2 = {"Position arrived. MOVE FORWARD .\n",409.752075,-308.770081,611.204834,-180.000000,1.000406,36.999977};//move_to_angles [1,2,3,4,5,6] [-37,55,-18,0,52,0] 10 60 0 0
//Neo_POSE return_put_down = {"Position arrived. Return_put_down1 .\n",597.090454,1.133256,496.172272,-179.222595,-0.995977,-0.642990};//move_to_angles [1,2,3,4,5,6] [0,69,-18,1,40,0] 10 60 0 0
/*  2020-07-16 4cup
Neo_POSE return_put_down1_1 = {"Position arrived. Return_put_down1_1 .\n",521.530212,-159.448029,498.316620,-180.000000,-1.000290,17.000025};//move_to_angles [1,2,3,4,5,6] [-17,33,48,0,10,0] 10 60 0 0
Neo_POSE return_put_down1_2 = {"Position arrived. Return_put_down1_2 .\n",522.891968,-159.864365,490.057678,-180.000000,0.000480,17.000025};//move_to_angles [1,2,3,4,5,6] [-17,33,50,0,7,0] 10 60 0 0
Neo_POSE return_put_down2_1 = {"Position arrived. Return_put_down2_1 .\n",545.359863,0.000000,498.316620,-180.000000,-1.000290,0.000000};//move_to_angles [1,2,3,4,5,6] [0,33,48,0,10,0] 10 60 0 0
Neo_POSE return_put_down2_2 = {"Position arrived. Return_put_down2_2 .\n",546.783997,0.000000,490.056641,-180.000000,0.000327,0.000000};//move_to_angles [1,2,3,4,5,6] [0,33,50,0,7,0] 10 60 0 0
Neo_POSE return_put_down3_1 = {"Position arrived. Return_put_down3_1 .\n",429.678253,-75.763680,491.105530,-180.000000,-1.000024,9.999975};//move_to_angles [1,2,3,4,5,6] [-10,9,82,0,0,0] 10 60 0 0
Neo_POSE return_put_down3_2 = {"Position arrived. Return_put_down3_2 .\n",429.041138,-75.651344,477.698608,-180.000000,-0.000305,9.999975};//move_to_angles [1,2,3,4,5,6] [-10,9,85,0,-4,0] 10 60 0 0
Neo_POSE return_put_down4_1 = {"Position arrived. Return_put_down4_1 .\n",436.240204,7.614415,491.102386,-180.000000,-1.000482,-0.999976};//move_to_angles [1,2,3,4,5,6] [1,9,82,0,0,0] 10 60 0 0
Neo_POSE return_put_down4_2 = {"Position arrived. Return_put_down4_2 .\n",435.902527,7.608521,482.753754,-180.000000,0.000000,-0.999976};//move_to_angles [1,2,3,4,5,6] [1,9,84,0,-3,0] 10 60 0 0
*/
Neo_POSE return_put_down1_1 = {"Position arrived. Return_put_down1_1 .\n",480.102203,-93.293335,509.283508,-180.000000,-0.000433,10.996655};//move_to_angles [1,2,3,4,5,6] [-11,20,65,0,5,0] 10 60 0 0
Neo_POSE return_put_down1_2 = {"Position arrived. Return_put_down1_2 .\n",481.190735,-93.476128,484.008514,-180.000000,-0.000336,10.993360};//move_to_angles [1,2,3,4,5,6] [-11,20,70,0,0,0] 10 60 0 0
Neo_POSE return_put_down2_1 = {"Position arrived. Return_put_down2_1 .\n",488.414673,25.545391,509.288696,-180.000000,0.000330,-2.993994};//move_to_angles [1,2,3,4,5,6] [3,20,65,0,5,0] 10 60 0 0
Neo_POSE return_put_down2_2 = {"Position arrived. Return_put_down2_2 .\n",489.515106,25.636831,484.011627,-180.000000,0.000122,-2.997949};//move_to_angles [1,2,3,4,5,6] [3,20,70,0,0,0] 10 60 0 0

// Gripper Pose
Gripper_POSE CLOSE = {"Gripper","close"};
Gripper_POSE OPEN = {"Gripper","open"};

// START: pre-work for N1
string setGoal(POSE pose)
{
    //tell the action client that we want to spin a thread by default  
    MoveBaseClient ac("move_base", true);  
      
    //wait for the action server to come up  
    while(!ac.waitForServer(ros::Duration(10.0)))
    {  
        ROS_WARN("Waiting for the move_base action server to come up.\n");  
    }  
    //ac.waitForServer(ros::Duration(60.0));
  
    move_base_msgs::MoveBaseGoal goal;  
      
    //we'll send a goal to the robot to move 1 meter forward  
    goal.target_pose.header.frame_id = "map";  
    goal.target_pose.header.stamp = ros::Time::now();  
    goal.target_pose.pose.position.x = pose.X; 
    goal.target_pose.pose.position.y = pose.Y;  
    goal.target_pose.pose.position.z = pose.Z;   
    goal.target_pose.pose.orientation.x = pose.or_x;
    goal.target_pose.pose.orientation.y = pose.or_y;
    goal.target_pose.pose.orientation.z = pose.or_z;
    goal.target_pose.pose.orientation.w = pose.or_w;   
    
    printf("Get to the destination now...\n");  
    
    ac.sendGoal(goal);  
      
    ac.waitForResult();  
      
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){  
    //    ROS_INFO("ROS_ERROR: It is successful\n");
       printf("It is successful!\n");
       return "t";
    }else{  
    //    ROS_ERROR("ROS_ERROR: The base failed move to goal!!!\n");
       printf("The base failed move to goal!!!\n");  
       return "u";
    }   
}

// Neo TAKE
ros::ServiceClient gripper_client;
ros::ServiceClient client1;
ros::ServiceClient Move_to_angles;
neo_msgs::MoveToPose MoveToPose_msg;
neo_msgs::MoveToAngles MoveToAngles_msg;
neo_msgs::SetEOATAction SetEOATAction_msg;
string setPOSE(Neo_POSE pose)
{
	string POSE_NAME = pose.Step_Name;
	MoveToPose_msg.request.pose.x = pose.X;
	MoveToPose_msg.request.pose.y = pose.Y;
	MoveToPose_msg.request.pose.z = pose.Z;
	MoveToPose_msg.request.pose.Rx = pose.Rx;
	MoveToPose_msg.request.pose.Ry = pose.Ry;
	MoveToPose_msg.request.pose.Rz = pose.Rz;
	client1.call(MoveToPose_msg);
	//printf("%s \n",POSE_NAME.c_str());
	return "success";
}

string setGripper_POSE(Gripper_POSE state)
{
	string STATE = state.ACTION;
	SetEOATAction_msg.request.name = state.NAME;
	SetEOATAction_msg.request.action = state.ACTION;
	gripper_client.call(SetEOATAction_msg);
	//printf("Gripper %s \n",STATE.c_str());
	return "success";
}

void poseCallback(const std_msgs::String::ConstPtr &msg)
{
    printf("Topic is Subscriber.\n");
    std::cout<<"Get topic command text: " << msg->data << std::endl;
    
    Callback_flag = true;
    msg_str = msg->data;
}
// END: pre-work for N1

void Return_Put_Down()
{
    if(return_put_down_num==0){
        setPOSE(return_put_down1_1);
        setPOSE(return_put_down1_2);
    }else if(return_put_down_num==1){
        setPOSE(return_put_down2_1);
        setPOSE(return_put_down2_2);
    }
}

void Callback_Calibration_Arm_Finish(const std_msgs::Bool::ConstPtr &msg)
{
    WAIT = msg->data;
    if(msg_str == TAKE_TO_GOAL1_CAFE_new){
        //setPOSE(move_forward_new2);
        // Gripper CLOSED
        setGripper_POSE(CLOSE);
        
        //setPOSE(move_forward_new1);
        
        setPOSE(go_back_to_ready_pose);

        setPOSE(fold);
        // END: Movements for OMNI6

        
        // DESTINATION - TAKE TO WHICH TABLE
        msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
        
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(cafe_goal1);

        // Pose 1 - READY POSE
        
        setPOSE(take_ready_pose);

        // Pose 2 - MOVE FORWARD
        
        setPOSE(take_move_forward1);

        // Pose 2-1 - Put it down briefly on customers' table
        setPOSE(take_move_forward2);

        setPOSE(take_move_forward3);
    
        setPOSE(take_move_forward4);

        // Gripper OPENED
        setGripper_POSE(OPEN);

        // Pose 3 - Go back to READY POSE
        setPOSE(take_ready_pose);

        // Gripper CLOSED
        setGripper_POSE(CLOSE);

        // Pose 4- FOLD
        setPOSE(fold);

        // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
        // GO HOME
        arrive_position = setGoal(cafe_home);
        printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
    }else  if(msg_str == TAKE_TO_GOAL2_CAFE_new){
        //setPOSE(move_forward_new2);
        // Gripper CLOSED
        setGripper_POSE(CLOSE);
        
        //setPOSE(move_forward_new1);
        
        setPOSE(go_back_to_ready_pose);

        setPOSE(fold);
        // END: Movements for OMNI6

        
        // DESTINATION - TAKE TO WHICH TABLE
        msg_str = "TAKE TO GOAL Cafe GOAL2 NOW....\n";
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(front_buffer1_2_6_7);
        arrive_position = setGoal(cafe_goal2_1);
        //arrive_position = setGoal(buffer2_7);
        arrive_position = setGoal(cafe_goal2);

        // Pose 1 - READY POSE
        
        setPOSE(take_ready_pose);

        // Pose 2 - MOVE FORWARD
        
        setPOSE(take_move_forward1);

        // Pose 2-1 - Put it down briefly on customers' table
        setPOSE(take_move_forward2);

        setPOSE(take_move_forward3);
    
        setPOSE(take_move_forward4);

        // Gripper OPENED
        setGripper_POSE(OPEN);

        // Pose 3 - Go back to READY POSE
        setPOSE(take_ready_pose);

        // Gripper CLOSED
        setGripper_POSE(CLOSE);

        // Pose 4- FOLD
        setPOSE(fold);

        // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
        // GO HOME
        //arrive_position = setGoal(buffer2_7);
        arrive_position = setGoal(back_buffer1_2_6_7_tmp1);
        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        arrive_position = setGoal(cafe_home);
        printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
    }else  if(msg_str == TAKE_TO_GOAL3_CAFE_new){
        //setPOSE(move_forward_new2);
        // Gripper CLOSED
        setGripper_POSE(CLOSE);
        
        //setPOSE(move_forward_new1);
        
        setPOSE(go_back_to_ready_pose);

        setPOSE(fold);
        // END: Movements for OMNI6

        
        // DESTINATION - TAKE TO WHICH TABLE
        msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
        
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(front_buffer1_2_6_7);
        arrive_position = setGoal(buffer3_8);
        arrive_position = setGoal(cafe_goal3_1);
        arrive_position = setGoal(cafe_goal3);

        // Pose 1 - READY POSE
        
        setPOSE(take_ready_pose);

        // Pose 2 - MOVE FORWARD
        
        setPOSE(take_move_forward1);

        // Pose 2-1 - Put it down briefly on customers' table
        setPOSE(take_move_forward2);

        setPOSE(take_move_forward3);
    
        setPOSE(take_move_forward4);

        // Gripper OPENED
        setGripper_POSE(OPEN);

        // Pose 3 - Go back to READY POSE
        setPOSE(take_ready_pose);

        // Gripper CLOSED
        setGripper_POSE(CLOSE);

        // Pose 4- FOLD
        setPOSE(fold);

        // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
        // GO HOME
        arrive_position = setGoal(back_buffer2_3_7_8_tmp1);
        arrive_position = setGoal(buffer3_8);
        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(cafe_home);
        printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
    }else  if(msg_str == TAKE_TO_GOAL6_CAFE_new){
        //setPOSE(move_forward_new2);
        // Gripper CLOSED
        setGripper_POSE(CLOSE);
        
        //setPOSE(move_forward_new1);
        
        setPOSE(go_back_to_ready_pose);

        setPOSE(fold);
        // END: Movements for OMNI6

        
        // DESTINATION - TAKE TO WHICH TABLE
        msg_str = "TAKE TO GOAL Cafe GOAL6 NOW....\n";
        
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(cafe_goal6);

        // Pose 1 - READY POSE
        
        setPOSE(take_ready_pose);

        // Pose 2 - MOVE FORWARD
        
        setPOSE(take_move_forward1);

        // Pose 2-1 - Put it down briefly on customers' table
        setPOSE(take_move_forward2);

        setPOSE(take_move_forward3);
    
        setPOSE(take_move_forward4);

        // Gripper OPENED
        setGripper_POSE(OPEN);

        // Pose 3 - Go back to READY POSE
        setPOSE(take_ready_pose);

        // Gripper CLOSED
        setGripper_POSE(CLOSE);

        // Pose 4- FOLD
        setPOSE(fold);

        // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
        // GO HOME
        arrive_position = setGoal(cafe_home);
        printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
    }else  if(msg_str == TAKE_TO_GOAL7_CAFE_new){
        //setPOSE(move_forward_new2);
        // Gripper CLOSED
        setGripper_POSE(CLOSE);
        
        //setPOSE(move_forward_new1);
        
        setPOSE(go_back_to_ready_pose);

        setPOSE(fold);
        // END: Movements for OMNI6

        
        // DESTINATION - TAKE TO WHICH TABLE
        msg_str = "TAKE TO GOAL Cafe GOAL7 NOW....\n";
        
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(front_buffer1_2_6_7);
        arrive_position = setGoal(buffer2_7);
        arrive_position = setGoal(cafe_goal7);

        // Pose 1 - READY POSE
        
        setPOSE(take_ready_pose);

        // Pose 2 - MOVE FORWARD
        
        setPOSE(take_move_forward1);

        // Pose 2-1 - Put it down briefly on customers' table
        setPOSE(take_move_forward2);

        setPOSE(take_move_forward3);
    
        setPOSE(take_move_forward4);

        // Gripper OPENED
        setGripper_POSE(OPEN);

        // Pose 3 - Go back to READY POSE
        setPOSE(take_ready_pose);

        // Gripper CLOSED
        setGripper_POSE(CLOSE);

        // Pose 4- FOLD
        setPOSE(fold);

        // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
        // GO HOME
        arrive_position = setGoal(buffer2_7);
        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        arrive_position = setGoal(cafe_home);
        printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
    }else  if(msg_str == TAKE_TO_GOAL8_CAFE_new){
        //setPOSE(move_forward_new2);
        // Gripper CLOSED
        setGripper_POSE(CLOSE);
        
        //setPOSE(move_forward_new1);
        
        setPOSE(go_back_to_ready_pose);

        setPOSE(fold);
        // END: Movements for OMNI6

        
        // DESTINATION - TAKE TO WHICH TABLE
        msg_str = "TAKE TO GOAL Cafe GOAL8 NOW....\n";
        
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(front_buffer1_2_6_7);
        arrive_position = setGoal(buffer3_8);
        arrive_position = setGoal(cafe_goal8);

        // Pose 1 - READY POSE
        
        setPOSE(take_ready_pose);

        // Pose 2 - MOVE FORWARD
        
        setPOSE(take_move_forward1);

        // Pose 2-1 - Put it down briefly on customers' table
        setPOSE(take_move_forward2);

        setPOSE(take_move_forward3);
    
        setPOSE(take_move_forward4);

        // Gripper OPENED
        setGripper_POSE(OPEN);

        // Pose 3 - Go back to READY POSE
        setPOSE(take_ready_pose);

        // Gripper CLOSED
        setGripper_POSE(CLOSE);

        // Pose 4- FOLD
        setPOSE(fold);

        // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
        // GO HOME
        arrive_position = setGoal(buffer3_8);
        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        arrive_position = setGoal(buffer1_6);
        arrive_position = setGoal(cafe_home);
        printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
    }else  if(msg_str == COLLECT_TO_GOAL1_CAFE_new){
        //setPOSE(move_forward_new2);
        setGripper_POSE(CLOSE);

        setPOSE(fold);
        
        msg_str = "COLLECT The Cafe GOAL1 To Dish Return NOW....\n";
        
        arrive_position = setGoal(buffer1_6);
        
        arrive_position = setGoal(cafe_return_tmp);
        
        arrive_position = setGoal(cafe_return);
        
        Return_Put_Down();
        
        setGripper_POSE(OPEN);
        
        setPOSE(ready_pose);
        
        setGripper_POSE(CLOSE);

        setPOSE(fold);

        arrive_position = setGoal(cafe_return_tmp);

        arrive_position = setGoal(cafe_home);
        
        printf("Return success~~~\n");
        return_put_down_num = (return_put_down_num + 1) % 2;
    }else  if(msg_str == COLLECT_TO_GOAL2_CAFE_new){
        //setPOSE(move_forward_new2);
        setGripper_POSE(CLOSE);

        setPOSE(fold);
        
        msg_str = "COLLECT The Cafe GOAL2 To Dish Return NOW....\n";
        
        arrive_position = setGoal(back_buffer1_2_6_7_tmp1);

        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        
        //arrive_position = setGoal(buffer1_6);
        
        arrive_position = setGoal(cafe_return_tmp);
        
        arrive_position = setGoal(cafe_return);
        
        Return_Put_Down();
        
        setGripper_POSE(OPEN);
        
        setPOSE(ready_pose);
        
        setGripper_POSE(CLOSE);

        setPOSE(fold);

        arrive_position = setGoal(cafe_return_tmp);

        arrive_position = setGoal(cafe_home);
        
        printf("Return success~~~\n");
        return_put_down_num = (return_put_down_num + 1) % 2;
    }else  if(msg_str == COLLECT_TO_GOAL3_CAFE_new){
        //setPOSE(move_forward_new2);
        setGripper_POSE(CLOSE);

        setPOSE(fold);
        
        msg_str = "COLLECT The Cafe GOAL3 To Dish Return NOW....\n";
        
        arrive_position = setGoal(back_buffer2_3_7_8_tmp1);
        
        arrive_position = setGoal(buffer3_8);
        
        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        
        arrive_position = setGoal(buffer1_6);
        
        arrive_position = setGoal(cafe_return_tmp);
        
        arrive_position = setGoal(cafe_return);
        
        Return_Put_Down();
        
        setGripper_POSE(OPEN);
        
        setPOSE(ready_pose);
        
        setGripper_POSE(CLOSE);

        setPOSE(fold);

        arrive_position = setGoal(cafe_return_tmp);

        arrive_position = setGoal(cafe_home);
        
        printf("Return success~~~\n");
        return_put_down_num = (return_put_down_num + 1) % 2;
    }else  if(msg_str == COLLECT_TO_GOAL6_CAFE_new){
        //setPOSE(move_forward_new2);
        setGripper_POSE(CLOSE);

        setPOSE(fold);
        
        msg_str = "COLLECT The Cafe GOAL6 To Dish Return NOW....\n";
        
        arrive_position = setGoal(cafe_return_tmp);
        
        arrive_position = setGoal(cafe_return);
        
        Return_Put_Down();
        
        setGripper_POSE(OPEN);
        
        setPOSE(ready_pose);
        
        setGripper_POSE(CLOSE);

        setPOSE(fold);

        arrive_position = setGoal(cafe_return_tmp);

        arrive_position = setGoal(cafe_home);
        
        printf("Return success~~~\n");
        return_put_down_num = (return_put_down_num + 1) % 2;
    }else  if(msg_str == COLLECT_TO_GOAL7_CAFE_new){
        //setPOSE(move_forward_new2);
        setGripper_POSE(CLOSE);

        setPOSE(fold);
        
        msg_str = "COLLECT The Cafe GOAL7 To Dish Return NOW....\n";
        
        arrive_position = setGoal(buffer2_7);

        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        
        //arrive_position = setGoal(buffer1_6);
        
        arrive_position = setGoal(cafe_return_tmp);
        
        arrive_position = setGoal(cafe_return);
        
        Return_Put_Down();
        
        setGripper_POSE(OPEN);
        
        setPOSE(ready_pose);
        
        setGripper_POSE(CLOSE);

        setPOSE(fold);

        arrive_position = setGoal(cafe_return_tmp);

        arrive_position = setGoal(cafe_home);
        
        printf("Return success~~~\n");
        return_put_down_num = (return_put_down_num + 1) % 2;
    }else  if(msg_str == COLLECT_TO_GOAL8_CAFE_new){
        //setPOSE(move_forward_new2);
        setGripper_POSE(CLOSE);

        setPOSE(fold);
        
        msg_str = "COLLECT The Cafe GOAL8 To Dish Return NOW....\n";
        
        arrive_position = setGoal(buffer3_8);
        
        arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
        
        arrive_position = setGoal(buffer1_6);
        
        arrive_position = setGoal(cafe_return_tmp);
        
        arrive_position = setGoal(cafe_return);
        
        Return_Put_Down();
        
        setGripper_POSE(OPEN);
        
        setPOSE(ready_pose);
        
        setGripper_POSE(CLOSE);

        setPOSE(fold);

        arrive_position = setGoal(cafe_return_tmp);

        arrive_position = setGoal(cafe_home);
        
        printf("Return success~~~\n");
        return_put_down_num = (return_put_down_num + 1) % 2;
    }else  if(msg_str == TEST){
        //arrive_position = setGoal(cafe_home);
        setGripper_POSE(CLOSE);
        setPOSE(fold);
        printf("TEST success~~~\n");
    }

}


// int main(int argc, char* argv[]) // at send_goal
int main(int argc, char **argv) 
{
    ros::init(argc, argv, "mix");
    ros::NodeHandle handle;

// Publisher topic to QR code to detection and move arm
    ros::Publisher pub_calibration_arm = handle.advertise<std_msgs::Bool>("calibration_arm",1);
// Publisher topic to choose which mode to gripper 0:TAKE-NEW 1:COLLECT 2:TAKE-ORI
     ros::Publisher pub_grasping_mode = handle.advertise<std_msgs::Int32>("grasping_mode",1);    
// START: for N1

    // pose_topic_pub: to control the robot arm in advance, therefore move to the coordinate.
    // subscribe the pubisher. The file located at: /src/dashgo/dashgo_sendcoordinate/nodes/order_goal_test.cpp
    ros::Subscriber sub_destination = handle.subscribe("destination_topic", 10, poseCallback); //poseCallback is the call back function name.
    // setHome(pub_initialpose);
    ROS_INFO_STREAM("Finished set a initial position.\n");
    printf("Finished set a initial position.\n");
    std_msgs::String msg;

// END: for N1

    // Subscribe the topic to know can do next step(goal)
    ros::Subscriber sub_calibration_arm_finish = handle.subscribe("detection_calibration_arm_finish",10,Callback_Calibration_Arm_Finish); //poseCallback is the call back function name.

// START: for OMNI6

    //ros::ServiceClient gripper_client = handle.serviceClient<neo_msgs::SetEOATAction>("neo_set_EOAT_action");
	//ros::ServiceClient client1 = handle.serviceClient<neo_msgs::MoveToPose>("neo_move_to_pose");
	//neo_msgs::MoveToPose MoveToPose_msg;
    //neo_msgs::SetEOATAction SetEOATAction_msg;
	
	gripper_client = handle.serviceClient<neo_msgs::SetEOATAction>("neo_set_EOAT_action");
	client1 = handle.serviceClient<neo_msgs::MoveToPose>("neo_move_to_pose");
    Move_to_angles = handle.serviceClient<neo_msgs::MoveToAngles>("neo_move_to_angles");
    
    // Set the OMNI6 status
    MoveToPose_msg.request.velocity = 10.0;
    MoveToPose_msg.request.acceleration = 50.0;
    MoveToPose_msg.request.relative = false;
    MoveToPose_msg.request.block = true; 
    // angles
    MoveToAngles_msg.request.velocity = 10.0;
    MoveToAngles_msg.request.acceleration = 60.0;
    MoveToAngles_msg.request.relative = false;
    MoveToAngles_msg.request.block = true; 

// END: for OMNI6


// START: Movements for N1

    while(ros::ok())
    {
       if(Callback_flag == true)
        {
            Callback_flag = false;

            if(msg_str == GOHOME)
            {
                msg_str = "Test: GO HOME NOW...\n";
                arrive_position = setGoal(home);
            }
            else  if(msg_str == GOHOME_2)
            {
                arrive_position = setGoal(home2);
                msg_str = "Test: GO HOME 2 NOW...\n";
            }
			else  if(msg_str == Cafe_GOHOME)
            {
				arrive_position = setGoal(buffer2_7);
				arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_home);
                msg_str = "Test: GO CAFE HOME NOW...\n"; 
            }
            else  if(msg_str == GOGOAL1)
            {
                arrive_position = setGoal(goal1);
                msg_str = "Test: GET TO GOAL 1 NOW....\n";

            }else  if(msg_str == GOGOAL2)
            {
                msg_str = "Test: GET TO GOAL 2 NOW....\n";
                arrive_position = setGoal(goal2);
            }else  if(msg_str == GOGOAL3)
            {
                msg_str = "Test: GET TO GOAL 3 NOW....\n";
                arrive_position = setGoal(goal3);
            }else  if(msg_str == GOGOAL4)
            {
                msg_str = "Test: GET TO GOAL 4 NOW....\n";
                arrive_position = setGoal(goal4);
            }
            else  if(msg_str == GOAL1_1)
            {
                msg_str = "Test: GET TO GOAL 1_1 NOW....\n";
                arrive_position = setGoal(goal1_1);
            }
            else  if(msg_str == GOAL1_2)
            {
                msg_str = "Test: GET TO GOAL 1_2 NOW....\n";
                arrive_position = setGoal(goal1_2);
            }
            else  if(msg_str == GOAL2_1)
            {
                msg_str = "Test: GET TO GOAL 2_1 NOW....\n";
                arrive_position = setGoal(goal2_1);
            }
            else  if(msg_str == GOAL2_2)
            {
                msg_str = "Test: GET TO GOAL 2_2 NOW....\n";
                arrive_position = setGoal(goal2_2);
            }
            /*============  fix  ===========*/
            
            else  if(msg_str == Cafe_GOAL1)
            {
                msg_str = "Test: GET TO GOAL cafe 1 NOW....\n";
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_goal1);
            }
            else  if(msg_str == Cafe_GOAL2)
            {
                msg_str = "Test: GET TO GOAL cafe 2 NOW....\n";
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(cafe_goal2);
            }
            else  if(msg_str == Cafe_GOAL3)
            {
                msg_str = "Test: GET TO GOAL cafe 3 NOW....\n";
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(cafe_goal3);
            }
            else  if(msg_str == Cafe_GOAL4)
            {
                msg_str = "Test: GET TO GOAL cafe 4 NOW....\n";
                arrive_position = setGoal(cafe_goal4);
            }
			else  if(msg_str == Cafe_GOAL5)
            {
                msg_str = "Test: GET TO GOAL cafe 5 NOW....\n";
                arrive_position = setGoal(buffer5);
                arrive_position = setGoal(cafe_goal5);
            }
            else  if(msg_str == Cafe_GOAL6)
            {
                msg_str = "Test: GET TO GOAL cafe 6 NOW....\n";
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_goal6);
            }
            else  if(msg_str == Cafe_GOAL7)
            {
                msg_str = "Test: GET TO GOAL cafe 7 NOW....\n";
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(cafe_goal7);
            }
            else  if(msg_str == Cafe_GOAL8)
            {
                msg_str = "Test: GET TO GOAL cafe 8 NOW....\n";
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(cafe_goal8);
            }
            /* not setting
            else  if(msg_str == Cafe_GOAL9)
            {
                msg_str = "Test: GET TO GOAL cafe 9 NOW....\n";
                arrive_position = setGoal(cafe_goal9);
            }
            else  if(msg_str == Cafe_GOAL10)
            {
                msg_str = "Test: GET TO GOAL cafe 10 NOW....\n";
                arrive_position = setGoal(cafe_goal10);
            }
            */
            else  if(msg_str == Cafe_GOAL11)
            {
                msg_str = "Test: GET TO GOAL cafe 11 NOW....\n";
                arrive_position = setGoal(cafe_goal11);
            }
            else  if(msg_str == Cafe_GOAL12)
            {
                msg_str = "Test: GET TO GOAL cafe 12 NOW....\n";
                arrive_position = setGoal(cafe_goal12);
            }
            else  if(msg_str == Cafe_GOAL13_14)
            {
                msg_str = "Test: GET TO GOAL cafe 13 14 NOW....\n";
                arrive_position = setGoal(cafe_goal13_14);
            }
            else  if(msg_str == Cafe_GOAL15_16)
            {
                msg_str = "Test: GET TO GOAL cafe 15 16 NOW....\n";
                arrive_position = setGoal(cafe_goal15_16);
            }
            /*=============================*/
            else  if(msg_str == COLLECT_FROM_GOAL_1_1)                       // COLLECT FROM GOAL 1-1
            {
                // START: Movements for OMNI6
		        // START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL 1-1 NOW....\n";
                arrive_position = setGoal(goal1_1);
                
                // Pose 1 - READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	            // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on home's table
                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.854065;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 594.515808;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.000027;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.806641;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 592.758301;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.999460;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.731262;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 590.990906;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -3.000571;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");

                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }
            else  if(msg_str == COLLECT_FROM_GOAL_1_2)                       // COLLECT FROM GOAL 1-2
            {
                // START: Movements for OMNI6
		        // START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL 1-2 NOW....\n";
                arrive_position = setGoal(goal1_2);
                
                // Pose 1 - READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	            // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on home's table
                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.854065;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 594.515808;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.000027;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.806641;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 592.758301;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.999460;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.731262;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 590.990906;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -3.000571;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");
                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
                
            }
            else  if(msg_str == COLLECT_FROM_GOAL_2_1)                       // COLLECT FROM GOAL 2-1
            {
               // START: Movements for OMNI6
		        // START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL 2-1 NOW....\n";
                arrive_position = setGoal(goal2_1);
                
                // Pose 1 - READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	            // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on home's table
                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.854065;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 594.515808;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.000027;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.806641;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 592.758301;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.999460;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.731262;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 590.990906;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -3.000571;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
                        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
                // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");

                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == COLLECT_FROM_GOAL_2_2)                       // COLLECT FROM GOAL 2-2
            {
                // START: Movements for OMNI6
		        // START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL 2-2 NOW....\n";
                arrive_position = setGoal(goal2_2);
                
                // Pose 1 - READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	            // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on home's table
                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.854065;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 594.515808;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.000027;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.806641;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 592.758301;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.999460;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 423.731262;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 590.990906;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -3.000571;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");
                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            /*              fix                */
            
            else  if(msg_str == COLLECT_FROM_GOAL1_CAFE)                       // COLLECT FROM GOAL 1-1
            {
                // START: Movements for OMNI6
		// START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL cafe 1 NOW....\n";
                arrive_position = setGoal(cafe_goal1);
                
                // Pose 1 - READY POSE
		// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		// move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(cafe_home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 2-1 - Put it down briefly on home's table
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.854065;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 594.515808;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.000027;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.806641;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.758301;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.999460;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.731262;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 590.990906;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -3.000571;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");

                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }
            else  if(msg_str == COLLECT_FROM_GOAL2_CAFE)                       // COLLECT FROM GOAL 1-1
            {
                // START: Movements for OMNI6
		// START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL cafe 1 NOW....\n";
                arrive_position = setGoal(cafe_goal2);
                
                // Pose 1 - READY POSE
		// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		// move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(cafe_home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 2-1 - Put it down briefly on home's table
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.854065;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 594.515808;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.000027;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.806641;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.758301;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.999460;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.731262;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 590.990906;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -3.000571;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");

                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }
            else  if(msg_str == COLLECT_FROM_GOAL3_CAFE)                       // COLLECT FROM GOAL 1-1
            {
                // START: Movements for OMNI6
		// START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL cafe 1 NOW....\n";
                arrive_position = setGoal(cafe_goal3);
                
                // Pose 1 - READY POSE
		// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		// move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(cafe_home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 2-1 - Put it down briefly on home's table
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.854065;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 594.515808;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.000027;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.806641;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.758301;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.999460;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.731262;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 590.990906;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -3.000571;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");

                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }

            else  if(msg_str == COLLECT_FROM_GOAL4_CAFE)                       // COLLECT FROM GOAL 1-1
            {
                // START: Movements for OMNI6
		// START: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE

                // DESTINATION - COLLECT FROM WHICH TABLE
                msg_str = "COLLECT FROM GOAL cafe 1 NOW....\n";
                arrive_position = setGoal(cafe_goal4);
                
                // Pose 1 - READY POSE
		// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
		// move_to_angles [1,2,3,4,5,6] [0,-10,80,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.096863;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.753113;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.000385;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

                // Pose 3 - TAKE IT UP
	        // move_to_angles [1,2,3,4,5,6] [0,-10,80,0,18,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 323.112366;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 599.790527;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 1.997350;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. TAKE IT UP.\n");

                // Pose 4- FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR GET CUP FROM CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(cafe_home);

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 2-1 - Put it down briefly on home's table
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,21,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.854065;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 594.515808;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.000027;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,22,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.806641;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 592.758301;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.999460;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,23,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.731262;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 590.990906;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -3.000571;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 5 - FOLD
		// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");

                // END: Movements for OMNI6
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }

           /*==================================*/
            else  if(msg_str == TAKE_TO_GOAL_1_1)                       // TAKE TO GOAL 1-1     // TAKE TO GOAL 1-1
            {  
                // START: Movements for OMNI6
                // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

		        // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 402.505066;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 642.095581;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 0.000430;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSEDTAKE_TO_GOAL1_CAFE
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

	        	// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.622009;
                MoveToPose_msg.request.pose.y = 0.003249;
                MoveToPose_msg.request.pose.z = 603.329041;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 4.000833;
                MoveToPose_msg.request.pose.Rz = -0.000439;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Pose 5 - FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");
                // END: Movements for OMNI6


                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL 1-1 NOW....\n";
                arrive_position = setGoal(goal1_1);


                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,0,68,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 369.808472;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 613.672180;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 2.001490;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on customers' table
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.891815;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 611.876892;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.996851;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.864380;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 610.153503;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.002797;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);
            
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.890686;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 608.351685;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.003404;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");


                // Pose 3 - Go back to READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. READY POSE. \n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }
            else  if(msg_str == TAKE_TO_GOAL_1_2)                       // TAKE TO GOAL 1-2     // TAKE TO GOAL 1-2
            {  
                // START: Movements for OMNI6
                // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

		        // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

	        	// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.622009;
                MoveToPose_msg.request.pose.y = 0.003249;
                MoveToPose_msg.request.pose.z = 603.329041;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 4.000833;
                MoveToPose_msg.request.pose.Rz = -0.000439;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Pose 5 - FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");
                // END: Movements for OMNI6


                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL 1-2 NOW....\n";
                arrive_position = setGoal(goal1_2);


                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,0,68,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 369.808472;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 613.672180;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 2.001490;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on customers' table
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.891815;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 611.876892;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.996851;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.864380;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 610.153503;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.002797;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);
            
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.890686;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 608.351685;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.003404;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");


                // Pose 3 - Go back to READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. READY POSE. \n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }
            else  if(msg_str == TAKE_TO_GOAL_2_1)                       // TAKE TO GOAL 2-1     // TAKE TO GOAL 2-1
            {  
                // START: Movements for OMNI6
                // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

		        // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

	        	// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.622009;
                MoveToPose_msg.request.pose.y = 0.003249;
                MoveToPose_msg.request.pose.z = 603.329041;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 4.000833;
                MoveToPose_msg.request.pose.Rz = -0.000439;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Pose 5 - FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");
                // END: Movements for OMNI6


                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL 2-1 NOW....\n";
                arrive_position = setGoal(goal2_1);


                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,0,68,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 369.808472;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 613.672180;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 2.001490;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on customers' table
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.891815;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 611.876892;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.996851;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.864380;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 610.153503;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.002797;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);
            
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.890686;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 608.351685;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.003404;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");


                // Pose 3 - Go back to READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. READY POSE. \n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }
            else  if(msg_str == TAKE_TO_GOAL_2_2)                       // TAKE TO GOAL 2-2     // TAKE TO GOAL 2-2
            {  
                // START: Movements for OMNI6
                // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE\n");

		        // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.895905;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 596.250977;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -0.004195;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Gripper CLOSEDTAKE_TO_GOAL1_CAFE
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed, item grabbed! \n");

	        	// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 423.622009;
                MoveToPose_msg.request.pose.y = 0.003249;
                MoveToPose_msg.request.pose.z = 603.329041;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 4.000833;
                MoveToPose_msg.request.pose.Rz = -0.000439;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                // Pose 4 - Go back to READY POSE
		        // move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 218.761261;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 581.685608;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -1.998999;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 4 arrived. READY POSE\n");

                // Pose 5 - FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 5 arrived. FOLD.\n");
                // END: Movements for OMNI6


                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL 2-2 NOW....\n";
                arrive_position = setGoal(goal2_2);


                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 1 arrived. READY POSE. \n");

                // Pose 2 - MOVE FORWARD
		        // move_to_angles [1,2,3,4,5,6] [0,0,68,0,20,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 369.808472;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 613.672180;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 2.001490;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                client1.call(MoveToPose_msg);
                printf("Position 2 arrived. MOVE FORWARD.\n");

                    // Pose 2-1 - Put it down briefly on customers' table
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,21,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.891815;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 611.876892;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.996851;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,22,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.864380;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 610.153503;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = 0.002797;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);
            
                    // move_to_angles [1,2,3,4,5,6] [0,0,68,0,23,0] 10 60 0 0
                    MoveToPose_msg.request.pose.x = 369.890686;
                    MoveToPose_msg.request.pose.y = 0.000000;
                    MoveToPose_msg.request.pose.z = 608.351685;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.003404;
                    MoveToPose_msg.request.pose.Rz = 0.000000;
                    client1.call(MoveToPose_msg);

                // Gripper OPENED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "open";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper opened! \n");


                // Pose 3 - Go back to READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-35,90,0,30,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = 171.816818;
                MoveToPose_msg.request.pose.y = 0.019767;
                MoveToPose_msg.request.pose.z = 624.198242;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = 5.002124;
                MoveToPose_msg.request.pose.Rz = -0.006592;
                client1.call(MoveToPose_msg);
                printf("Position 3 arrived. READY POSE. \n");

                // Gripper CLOSED
                SetEOATAction_msg.request.name = "Gripper";
                SetEOATAction_msg.request.action = "close";
                gripper_client.call(SetEOATAction_msg);
                printf("Gripper closed! \n");

                // Pose 4- FOLD
		        // move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.x = -113.988853;
                MoveToPose_msg.request.pose.y = 0.000000;
                MoveToPose_msg.request.pose.z = 488.099701;
                MoveToPose_msg.request.pose.Rx = -180.000000;
                MoveToPose_msg.request.pose.Ry = -2.003237;
                MoveToPose_msg.request.pose.Rz = 0.000000;
                printf("Position 4 arrived. FOLD.\n");
                client1.call(MoveToPose_msg);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");

            }
            else  if(msg_str == TAKE_TO_GOAL1_CAFE)                       // TAKE TO GOAL 2-2 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_goal1);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == TAKE_TO_GOAL2_CAFE)                       // TAKE TO GOAL 2 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(front_buffer1_2_6_7);
                arrive_position = setGoal(cafe_goal2_1);
                //arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(cafe_goal2);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                //arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(back_buffer1_2_6_7_tmp1);
                arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == TAKE_TO_GOAL3_CAFE)                       // TAKE TO GOAL 3 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(front_buffer1_2_6_7);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(cafe_goal3_1);
                arrive_position = setGoal(cafe_goal3);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(back_buffer2_3_7_8_tmp1);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }  
            else  if(msg_str == TAKE_TO_GOAL4_CAFE)                       // TAKE TO GOAL 4 (cafe)
            {
				// START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(buffer3_8);
                //arrive_position = setGoal(buffer4_14);
                arrive_position = setGoal(cafe_goal4);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                
                //arrive_position = setGoal(buffer4_14);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
			}
            else  if(msg_str == TAKE_TO_GOAL5_CAFE)                       // TAKE TO GOAL 5 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(buffer3_8);
                //arrive_position = setGoal(buffer4_14);
                //arrive_position = setGoal(buffer5_16);
                arrive_position = setGoal(cafe_goal5);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                //arrive_position = setGoal(buffer5_16);
                //arrive_position = setGoal(buffer4_14);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == TAKE_TO_GOAL6_CAFE)                       // TAKE TO GOAL 6 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_goal6);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == TAKE_TO_GOAL7_CAFE)                       // TAKE TO GOAL 7 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(front_buffer1_2_6_7);
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(cafe_goal7);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == TAKE_TO_GOAL8_CAFE)                       // TAKE TO GOAL 8 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(front_buffer1_2_6_7);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(cafe_goal8);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(back_buffer1_2_6_7_tmp2);
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == TAKE_TO_GOAL9_CAFE)                       // TAKE TO GOAL 9 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                // Pose 2 - MOVE FORWARD
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,20,0] 10 60 0 0
                setPOSE(move_forward);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

				// Pose 3 - TAKE IT UP
                // move_to_angles [1,2,3,4,5,6] [0,10,60,0,16,0] 10 60 0 0
                setPOSE(take_it_up);

                // Pose 4 - Go back to READY POSE
				// move_to_angles [1,2,3,4,5,6] [0,-30,95,0,27,0] 10 60 0 0
                setPOSE(go_back_to_ready_pose);

                // Pose 5 - FOLD
				// move_to_angles [1,2,3,4,5,6] [0,-90,105,0,77,0] 10 60 0 0
                setPOSE(fold);
                // END: Movements for OMNI6

				
                // DESTINATION - TAKE TO WHICH TABLE
                msg_str = "TAKE TO GOAL Cafe GOAL1 NOW....\n";
                
                //arrive_position = setGoal(cafe_goal9);

                // Pose 1 - READY POSE
                
                setPOSE(take_ready_pose);

                // Pose 2 - MOVE FORWARD
		        
                setPOSE(take_move_forward1);

                // Pose 2-1 - Put it down briefly on customers' table
                setPOSE(take_move_forward2);

                setPOSE(take_move_forward3);
            
                setPOSE(take_move_forward4);

                // Gripper OPENED
                setGripper_POSE(OPEN);

                // Pose 3 - Go back to READY POSE
                setPOSE(take_ready_pose);

                // Gripper CLOSED
                setGripper_POSE(CLOSE);

                // Pose 4- FOLD
                setPOSE(fold);

                // END: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE
                // GO HOME
                arrive_position = setGoal(cafe_home);
                printf("NEXT COMMAND PLEASE (HOME, COLLECT_FROM_GOAL_x_y, TAKE_TO_GOAL_x_y): \n");
            }
            else  if(msg_str == TAKE_TO_GOAL1_CAFE_new)                       // TAKE TO GOAL 2-2 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                //setPOSE(move_forward_new1);
                
                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == TAKE_TO_GOAL2_CAFE_new)                       // TAKE TO GOAL 2 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                //setPOSE(move_forward_new1);
                
                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

				pub_calibration_arm.publish(true);
            }
            else  if(msg_str == TAKE_TO_GOAL3_CAFE_new)                       // TAKE TO GOAL 3 (cafe)
            {
			// START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                //setPOSE(move_forward_new1);
                
                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

				pub_calibration_arm.publish(true);
            }
            else  if(msg_str == TAKE_TO_GOAL6_CAFE_new)                       // TAKE TO GOAL 6 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                //setPOSE(move_forward_new1);
                
                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

				pub_calibration_arm.publish(true);
            }
            else  if(msg_str == TAKE_TO_GOAL7_CAFE_new)                       // TAKE TO GOAL 7 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                //setPOSE(move_forward_new1);
                
                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == TAKE_TO_GOAL8_CAFE_new)                       // TAKE TO GOAL 8 (cafe)
            {
            // START: Movements for OMNI6
            // START: HERE GOES THE MOVEMENTS FOR TAKE ITEMS TO CUSTOMERS' TABLE

                // Pose 1 - READY POSE
                // move_to_angles [1,2,3,4,5,6] [0,-30,85,0,35,0] 10 60 0 0
                setPOSE(ready_pose);
                
                //setPOSE(move_forward_new1);
                
                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

				pub_calibration_arm.publish(true);
            }
            else  if(msg_str == COLLECT_TO_GOAL1_CAFE_new)
            {
                setPOSE(fold);
                
                arrive_position = setGoal(buffer1_6);
                
                arrive_position = setGoal(cafe_goal1);

                setPOSE(ready_pose);

                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == COLLECT_TO_GOAL2_CAFE_new)
            {
                setPOSE(fold);
                
                arrive_position = setGoal(buffer1_6);

                arrive_position = setGoal(front_buffer1_2_6_7);
                
                arrive_position = setGoal(cafe_goal2_1);
                //arrive_position = setGoal(buffer2_7);
                arrive_position = setGoal(cafe_goal2);

                setPOSE(ready_pose);

                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == COLLECT_TO_GOAL3_CAFE_new)
            {
                setPOSE(fold);
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(front_buffer1_2_6_7);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(cafe_goal3_1);
                arrive_position = setGoal(cafe_goal3);

                setPOSE(ready_pose);

                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == COLLECT_TO_GOAL6_CAFE_new)
            {
                setPOSE(fold);
                
                arrive_position = setGoal(buffer1_6);
                
                arrive_position = setGoal(cafe_goal6);

                setPOSE(ready_pose);

                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == COLLECT_TO_GOAL7_CAFE_new)
            {
                setPOSE(fold);
                
                arrive_position = setGoal(buffer1_6);
                
                arrive_position = setGoal(front_buffer1_2_6_7);
                
                arrive_position = setGoal(buffer2_7);
                
                arrive_position = setGoal(cafe_goal7);

                setPOSE(ready_pose);
                
                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == COLLECT_TO_GOAL8_CAFE_new)
            {
                setPOSE(fold);
                
                arrive_position = setGoal(buffer1_6);
                arrive_position = setGoal(front_buffer1_2_6_7);
                arrive_position = setGoal(buffer3_8);
                arrive_position = setGoal(cafe_goal8);

                setPOSE(ready_pose);

                setGripper_POSE(OPEN);

                pub_grasping_mode.publish(1);

                pub_calibration_arm.publish(true);
            }
            else  if(msg_str == TEST)                       
            {
                setPOSE(ready_pose);
                setGripper_POSE(OPEN);
                pub_grasping_mode.publish(1);
                pub_calibration_arm.publish(true);
                //setPOSE(fold);
                //arrive_position = setGoal(cafe_goal1);
                //setPOSE(ready_pose);
                //setGripper_POSE(OPEN);
                //setPOSE(take_move_forward4);
                
                //setGoal(cafe_return_tmp);
                //setGoal(cafe_return);   
                //arrive_position = setGoal(buffer1_6);
                //arrive_position = setGoal(cafe_goal1);
                //setPOSE(ready_pose);
                //system("play ~/dashgo_ws/src/qr_code/src/google_voice.mp3");
                //setPOSE(move_forward_new1);
                //setGripper_POSE(OPEN);
                //pub_grasping_mode.publish(1);
                //pub_calibration_arm.publish(true);
                // 20200323
                /*
                double dx = 0.023652,dy = 2.742952,drz = -1.015466,dxr = 0.04833983;
                double x = 0,y = 0,z = 0,rx = 0,ry = 0,rz = 0;
                for(int i = 0;i < 50;i ++)
                {    
                    //x = 156.800446 -( dx + dxr * i);
                    //y = -0.015033 + dy * ( i + 1 );
                    x = 156.800446 - 1.12031892 * (i+1);
                    y = -0.015033 + 2.442952 * ( i + 1 );
                    rz = 0.005493 + drz * ( i + 1 );
                    MoveToPose_msg.request.pose.x = x;
                    MoveToPose_msg.request.pose.y = y;
                    MoveToPose_msg.request.pose.z = 633.699585;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.000113;
                    MoveToPose_msg.request.pose.Rz = rz;
                    client1.call(MoveToPose_msg);
                    printf("angle [%d] success!\n",(i+1));
                }

                setPOSE(take_ready_pose);
                for(int i = 0;i < 50;i ++)
                {
                    x = 156.800446 - 1.12031892 * (i+1);
                    y = -0.015033 - 2.442952 * ( i + 1 );
                    rz = 0.005493 - drz * ( i + 1 );
                    MoveToPose_msg.request.pose.x = x;
                    MoveToPose_msg.request.pose.y = y;
                    MoveToPose_msg.request.pose.z = 633.699585;
                    MoveToPose_msg.request.pose.Rx = -180.000000;
                    MoveToPose_msg.request.pose.Ry = -1.000113;
                    MoveToPose_msg.request.pose.Rz = rz;
                    client1.call(MoveToPose_msg);
                    printf("angle [- %d] success!\n",(i+1));
                }
                */
            }
            else
            {
                msg_str = "WRONG INPUT, TYPE IT AGAIN !!!\n";
            }
        }
        ros::spinOnce();
    }

// END: Movements for N1

    return 0;

}
