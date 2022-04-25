#include "capteur_1/capteur.hpp"

using namespace std::chrono_literals;

CapteurPublisher::CapteurPublisher(std::string msg_addon="Test") : Node("Capteur_Node")
{
    pub_default_capteur = this->create_publisher<std_msgs::msg::String>("topic", 10);
    pub_point = this->create_publisher<weez_u_msgs::msg::MyPoint>("point_msg", 10);
    stored_add_on_msg = msg_addon;
    count = 0;
    clock = std::make_shared<rclcpp::Clock>(RCL_ROS_TIME);
    timer_ = this->create_wall_timer(1s, std::bind(&CapteurPublisher::timer_callback, this));

}

void CapteurPublisher::timer_callback()
{
    auto msg = std_msgs::msg::String();
    std::stringstream ss;
    ss << stored_add_on_msg << " - Message ID - " << count;
    msg.data =  ss.str();
    RCLCPP_INFO(this->get_logger(), "Publishing !");
    pub_default_capteur->publish(msg);

    auto my_point = weez_u_msgs::msg::MyPoint();
    my_point.header.stamp = clock->now();
    my_point.pose.position.x = 1.0;
    my_point.pose.position.y = -1.0;
    my_point.pose.position.z = 0.0;
    my_point.pose.orientation.w = 1.0;
    my_point.msg = ss.str();
    pub_point->publish(my_point);
    count++;

}

