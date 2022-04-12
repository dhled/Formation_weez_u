#include "capteur_1/service_serveur.hpp"


CapteurService::CapteurService(ros::NodeHandle* nh):
    nh_(*nh)
{
    pub_point = nh_.advertise<weez_u_msgs::MyPoint>("srv_point_msg", 50);
    current_point.header.stamp = ros::Time::now();
    current_point.pose.position.x = 1.0;
    current_point.pose.position.y = -1.0;
    current_point.pose.position.z = 0.0;
    current_point.pose.orientation.w = 1.0;
    current_point.msg = "No message";

    service = nh_.advertiseService("change_point", &CapteurService::service_callback, this);


}

void CapteurService::timer_callback(const ros::TimerEvent& event)
{
    current_point.header.stamp = ros::Time::now();
    pub_point.publish(current_point);
}

bool CapteurService::service_callback(weez_u_msgs::ChangePoint::Request &req, weez_u_msgs::ChangePoint::Response &res)
{
    current_point = req.point;
    res.result = "Success";
    res.msg = "Updated Point";
    ROS_INFO("Point Changed !");
    return true;
}



