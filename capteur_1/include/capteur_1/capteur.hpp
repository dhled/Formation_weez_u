#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP



#include "ros/ros.h"
#include "std_msgs/String.h"
#include "weez_u_msgs/MyPoint.h"

#include <sstream>

class CapteurPublisher
{
public:
    CapteurPublisher(ros::NodeHandle* nh, std::string msg_addon);
    ~CapteurPublisher() {};

    void timer_callback(const ros::TimerEvent& event);

private:
    ros::NodeHandle nh_;
    ros::Publisher pub_default_capteur;
    ros::Publisher pub_point;
    std::string stored_add_on_msg;
    ros::Timer timer;
    int count;
};

#endif