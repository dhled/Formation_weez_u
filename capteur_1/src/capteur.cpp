#include "capteur_1/capteur.hpp"


CapteurPublisher::CapteurPublisher(ros::NodeHandle* nh, std::string msg_addon="Test"):
    nh_(*nh)
{
    pub_default_capteur = nh_.advertise<std_msgs::String>("sensor_msg", 50); //Nom du topic / Taille du buffer de message
    pub_point = nh_.advertise<weez_u_msgs::MyPoint>("point_msg", 50);
    stored_add_on_msg = msg_addon;
    count = 0;

}

void CapteurPublisher::timer_callback(const ros::TimerEvent& event)
{
    std_msgs::String string_msg;
    std::stringstream ss;
    ss << stored_add_on_msg << " - Message ID - " << count;
    string_msg.data =  ss.str();
    ROS_INFO("Publishing !");
    pub_default_capteur.publish(string_msg);

    weez_u_msgs::MyPoint my_point;
    my_point.header.stamp = ros::Time::now();
    my_point.pose.position.x = 1.0;
    my_point.pose.position.y = -1.0;
    my_point.pose.position.z = 0.0;
    my_point.pose.orientation.w = 1.0;
    my_point.msg = ss.str();
    pub_point.publish(my_point);
    count++;

}

