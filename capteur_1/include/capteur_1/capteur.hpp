#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "weez_u_msgs/msg/my_point.hpp"
#include <chrono>
#include <sstream>

class CapteurPublisher : public rclcpp::Node
{
public:
    CapteurPublisher(std::string msg_addon);
    ~CapteurPublisher() {};

    void timer_callback();

private:
    rclcpp::Clock::SharedPtr clock;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_default_capteur;
    rclcpp::Publisher<weez_u_msgs::msg::MyPoint>::SharedPtr pub_point;
    std::string stored_add_on_msg;
    int count;
};

#endif