#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int32.h"
#include "Judge.h"

float L_Slope;
float R_Slope;
bool IsRed;
bool IsYellow;
bool IsGreen;
int L_Loc;
int R_Loc;

int Servo_Value;
bool IsGo;

using namespace std;


void bool_cb1(const std_msgs::Bool::ConstPtr& msg)
{
	IsRed = msg->data;
	ROS_INFO("yes_or_no: [%s]", msg->data ? "true" : "false");
}
void bool_cb2(const std_msgs::Bool::ConstPtr& msg)
{
	IsYellow = msg->data;
	ROS_INFO("yes_or_no: [%s]", msg->data ? "true" : "false");
}
void bool_cb3(const std_msgs::Bool::ConstPtr& msg)
{
	IsGreen = msg->data;
	ROS_INFO("yes_or_no: [%s]", msg->data ? "true" : "false");
}

void float_cb1(const std_msgs::Float32::ConstPtr& msg)
{
	L_Slope = msg->data;
	ROS_INFO("value: [%f]", msg->data);
}
void float_cb2(const std_msgs::Float32::ConstPtr& msg)
{
	R_Slope = msg->data;
	ROS_INFO("value: [%f]", msg->data);
}

void int_cb1(const std_msgs::Int32::ConstPtr& msg)
{
	L_Loc = msg->data;
	ROS_INFO("value: [%d]", msg->data);
}
void int_cb2(const std_msgs::Int32::ConstPtr& msg)
{
	R_Loc = msg->data;
	ROS_INFO("value: [%d]", msg->data);
}