#ifndef SERVICE_HPP
#define SERVICE_HPP


#include "ros/ros.h"
#include "weez_u_msgs/MyPoint.h"
#include "weez_u_msgs/ChangePoint.h"

#include <sstream>

class CapteurService
{
public:
    CapteurService(ros::NodeHandle* nh);
    ~CapteurService() {};

    void timer_callback(const ros::TimerEvent& event);
    bool service_callback(weez_u_msgs::ChangePoint::Request &req, weez_u_msgs::ChangePoint::Response &res);

private:
    ros::NodeHandle nh_;
    ros::Publisher pub_point;
    ros::ServiceServer service;
    weez_u_msgs::MyPoint current_point;
};

#endif