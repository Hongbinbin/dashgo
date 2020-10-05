#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include "std_msgs/Float64.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Bool.h"
#include <librealsense2/rs.hpp> // Include RealSense Cross Platform API
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <sensor_msgs/PointCloud2.h>
#include "neo_msgs/MoveToAngles.h"
#include "neo_msgs/JointAngles.h"
#include "neo_msgs/JointCurrent.h"
#include "neo_msgs/JointVelocity.h"
#include <zbar.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>

using namespace std;
using namespace cv;
using namespace zbar;
//static const std::string OPENCV_WINDOW="Image window";
const int camera_offset = 0;
double Distance = 10;
int range = -22;
int is_calibrate = 0,calibrate_frequency = 3;
bool OPEN_ARM_CALIBRATION = false;
int Grasping_Mode = 0;
float _angles [6] = {0, -34, 85, 0, 41, 0};

void Callback_Neo_Angles(const neo_msgs::JointAngles::ConstPtr &msg)
{
    for(int i=0;i<6;i++)
    {
        _angles[i] = msg->angles[i];
    }
}

void Callback_Calibration_Arm(const std_msgs::Bool::ConstPtr &msg)
{
    OPEN_ARM_CALIBRATION = msg->data;
}

void Callback_Grasping_Mode(const std_msgs::Int32::ConstPtr &msg)
{
    Grasping_Mode = msg->data;    
}

void draw(cv::Mat frame,Image::SymbolIterator symbol,ros::Publisher pub_calibration_arm_finish)
{
    ros::NodeHandle handle;
    // NEO 
    neo_msgs::MoveToAngles MoveToAngles_msg;
    ros::ServiceClient Move_to_angles;
    Move_to_angles = handle.serviceClient<neo_msgs::MoveToAngles>("neo_move_to_angles");
    // angles
    MoveToAngles_msg.request.velocity = 10.0;
    MoveToAngles_msg.request.acceleration = 60.0;
    MoveToAngles_msg.request.relative = false;
    MoveToAngles_msg.request.block = true; 
    // Publisher topic to talk to Mix.cpp can go next goal.
    int width = frame.cols;
    int height = frame.rows;
    int qr_center_x = 0,qr_center_y = 0;
    int qr_codeX_distance = 0;
    
    //scan camera center
    line(frame, Point((width/2)+camera_offset-8,(height/2)), Point((width/2)+camera_offset+8,(height/2)), Scalar( 0, 0, 255), 2, 8, 0);
    line(frame, Point((width/2)+camera_offset,(height/2)-8), Point((width/2)+camera_offset,(height/2)+8), Scalar( 0, 0, 255), 2, 8, 0);
    
    if (symbol->get_location_size() == 4)
    {
        qr_center_x = (symbol->get_location_x(0) + symbol->get_location_x(2))/2;
        qr_center_y = (symbol->get_location_y(0) + symbol->get_location_y(2))/2;
        //scan qr code
        line(frame, Point(symbol->get_location_x(0), symbol->get_location_y(0)), Point(symbol->get_location_x(1), symbol->get_location_y(1)), Scalar(0, 255, 0), 2, 8, 0);
        line(frame, Point(symbol->get_location_x(1), symbol->get_location_y(1)), Point(symbol->get_location_x(2), symbol->get_location_y(2)), Scalar(0, 255, 0), 2, 8, 0);
        line(frame, Point(symbol->get_location_x(2), symbol->get_location_y(2)), Point(symbol->get_location_x(3), symbol->get_location_y(3)), Scalar(0, 255, 0), 2, 8, 0);
        line(frame, Point(symbol->get_location_x(3), symbol->get_location_y(3)), Point(symbol->get_location_x(0), symbol->get_location_y(0)), Scalar(0, 255, 0), 2, 8, 0);
        
        //scan qr code center
        line(frame, Point(qr_center_x-15,qr_center_y-15), Point(qr_center_x-15,qr_center_y+15), Scalar(255, 0, 0), 2, 8, 0);
        line(frame, Point(qr_center_x-15,qr_center_y+15), Point(qr_center_x+15,qr_center_y+15), Scalar(255, 0, 0), 2, 8, 0);
        line(frame, Point(qr_center_x+15,qr_center_y+15), Point(qr_center_x+15,qr_center_y-15), Scalar(255, 0, 0), 2, 8, 0);
        line(frame, Point(qr_center_x+15,qr_center_y-15), Point(qr_center_x-15,qr_center_y-15), Scalar(255, 0, 0), 2, 8, 0);
        
        qr_codeX_distance = symbol->get_location_x(3) - symbol->get_location_x(0);
        printf("x_distance : %d \t qr_center_y : %d \n",qr_codeX_distance,qr_center_y);

        if(OPEN_ARM_CALIBRATION)
        {
            is_calibrate = is_calibrate % calibrate_frequency;
            printf("calibrate %d \n",is_calibrate);
            if(is_calibrate < 2)
            {
                is_calibrate++;
                if(qr_center_x<((width/2)+camera_offset-6))
                {
                    for(int i=0; i<6; i++)
                    {
                        MoveToAngles_msg.request.motor_ids.push_back((i+1));
                        MoveToAngles_msg.request.angles.push_back(_angles[i]);   
                    }
                    Move_to_angles.call(MoveToAngles_msg);
                    _angles[0] = _angles[0] + 1;
                    printf("Please move robot turn LEFT\n");
                }
                else if(qr_center_x>((width/2)+camera_offset+6))
                {
                    for(int i=0; i<6; i++)
                    {
                        MoveToAngles_msg.request.motor_ids.push_back((i+1));
                        MoveToAngles_msg.request.angles.push_back(_angles[i]);
                    }
                    Move_to_angles.call(MoveToAngles_msg);
                    _angles[0] = _angles[0] - 1;
                    printf("Please move robot turn Right\n");
                }
            }
            else
            {
                is_calibrate++;
                 
                int threshold = 280;

                if(Grasping_Mode == 0)
                {
                    _angles[1] = 45;
                    _angles[2] = 0;
                    _angles[3] = 0;
                    _angles[4] = 45;
                    _angles[5] = 0;
                    threshold = 216;
                    printf("TAKE\n");
                }
                else if(Grasping_Mode == 1)
                {
                    if(qr_center_y <= 235){    
                        if(_angles[1] >= 0){
                            _angles[1] = _angles[1] + 1;
                            _angles[2] = _angles[2] - 2;
                            _angles[4] = _angles[4] + 1;
                        }else{
                            _angles[1] = _angles[1] + 1;
                            _angles[2] = _angles[2] - 1;    
                        }
                    }else{
                        _angles[2] = _angles[2] + 1;
                        _angles[4] = _angles[4] - 1;
                    }

                    threshold = 280;

                    printf("COLLECT\n");
                   
                }
                
                for(int i=0; i<6; i++)
                {
                MoveToAngles_msg.request.motor_ids.push_back((i+1));
                MoveToAngles_msg.request.angles.push_back(_angles[i]);   
                }
                Move_to_angles.call(MoveToAngles_msg);   



                
                if(qr_codeX_distance > threshold)
                {
                    printf("All Finish\n");
                    range = -22;
                    pub_calibration_arm_finish.publish(false);
                    OPEN_ARM_CALIBRATION = false;
                }

            }
        }    
    }
}

void Move_Arm_To_Search_QRCODE()
{
    ros::NodeHandle handle;
    // NEO 
    neo_msgs::MoveToAngles MoveToAngles_msg;
    ros::ServiceClient Move_to_angles;
    Move_to_angles = handle.serviceClient<neo_msgs::MoveToAngles>("neo_move_to_angles");
    // angles
    MoveToAngles_msg.request.velocity = 10.0;
    MoveToAngles_msg.request.acceleration = 60.0;
    MoveToAngles_msg.request.relative = false;
    MoveToAngles_msg.request.block = true; 

    printf("Can`t Scan The QR CODE~ \n");
    printf("Please Move The QR CODE A Front Of The Camera , Thank you.\n");

    if((_angles[0]<=100)&&(_angles[0]>=-100)){
        if(range <= 0){
            if(range == -22){
                _angles[0] = 0;
            }
            range = range + 1;
            _angles[0] = _angles[0] + 1;
        }else{
            if(range == 1){
                _angles[0] = 0;
            }
            else if(range > 22){
                range = -23;
                system("play ~/dashgo_ws/src/qr_code/src/google_voice.mp3");
            }else{
                _angles[0] = _angles[0] - 1;
            }
            range = range + 1;
            printf("Searching Again\n");
        }
        printf("range = %d\n",range);
        for(int i=0; i<6; i++)
        {
            MoveToAngles_msg.request.motor_ids.push_back((i+1));
            MoveToAngles_msg.request.angles.push_back(_angles[i]);   
        }
        Move_to_angles.call(MoveToAngles_msg);
    }
}

void zbarscanner(cv_bridge::CvImagePtr cv_ptr,ros::Publisher pub_calibration_arm_finish)
{

    // Create a zbar reader
    ImageScanner scanner;

    // Configure the reader
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

        // Capture an OpenCV frame
        cv::Mat frame,frame_grayscale;
        frame=cv_ptr->image;
        // Convert to grayscale
        cvtColor(frame, frame_grayscale, CV_BGR2GRAY);

        // Obtain image data
        int width = frame_grayscale.cols;
        int height = frame_grayscale.rows;
        uchar *raw = (uchar *)(frame_grayscale.data);

        // Wrap image data
        Image image(width, height, "Y800", raw, width * height);

        // Scan the image for barcodes
        int FIND_QR_CODE = scanner.scan(image); //FIND_QR_CODE: '0':Not Find , '1':Find ;
        if((!FIND_QR_CODE) && (OPEN_ARM_CALIBRATION))
        {
           Move_Arm_To_Search_QRCODE();
        }

        // Extract results
        int counter = 0;
        for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
            //cout<< symbol->get_data() << endl;
            // Draw location of the symbols found
            draw(frame,symbol,pub_calibration_arm_finish);
            counter++;
        }

}

class ImageConverter
{
    ros::NodeHandle nh;

    image_transport::ImageTransport it;
    image_transport::Subscriber image_color_sub;
    image_transport::Subscriber image_distance_sub;
    image_transport::Publisher image_pub;
    ros::Subscriber neo_angles = nh.subscribe("neo_angles", 1, Callback_Neo_Angles);
    ros::Subscriber sub_calibration_arm = nh.subscribe("calibration_arm", 10, Callback_Calibration_Arm); //poseCallback is the call back function name.
    ros::Subscriber sub_grasping_mode = nh.subscribe("grasping_mode", 1, Callback_Grasping_Mode);
    ros::Publisher pub_calibration_arm_finish = nh.advertise<std_msgs::Bool>("detection_calibration_arm_finish",1);
    

  public:
    ImageConverter():it(nh)
    {
        //使用image_transport订阅图像话题“in” 和 发布图像话题“out”
        image_color_sub=it.subscribe("/camera/color/image_raw",1,&ImageConverter::imageCb,this);
        image_distance_sub=it.subscribe("/camera/depth/image_rect_raw",1,&ImageConverter::image_distance,this);
        image_pub=it.advertise("QR_CODE_DETECTION",1);

    }

    ~ImageConverter(){}

    //订阅回调函数
    void imageCb(const sensor_msgs::ImageConstPtr& msg)
    {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            //将ROS图像消息转化为适合Opencv的CvImage
            cv_ptr=cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::BGR8);
        }
        catch(cv_bridge::Exception& e)
        {
            ROS_ERROR("cv_bridge exception: %s",e.what());
            return;
        }

        zbarscanner(cv_ptr,pub_calibration_arm_finish);
        image_pub.publish(cv_ptr->toImageMsg());
    }

    void image_distance(const sensor_msgs::ImageConstPtr& msg)
    {
        cv_bridge::CvImagePtr cv_distance_ptr;
        try
        {
            //将ROS图像消息转化为适合Opencv的CvImage
            cv_distance_ptr=cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_16UC1);
        }
        catch(cv_bridge::Exception& e)
        {
            ROS_ERROR("cv_bridge exception: %s",e.what());
            return;
        }
        Distance = 0.001*cv_distance_ptr->image.at<u_int16_t>(320, 240);
        //std::cout<<Distance<<std::endl;
        
    }
    
};


int main(int argc, char **argv) {

    ros::init(argc,argv,"QR_CODE_DETECTION");
    ImageConverter ic;
    ros::spin();
    return 0;
}