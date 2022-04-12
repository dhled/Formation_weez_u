#include "capteur_1/capteur.hpp"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "capteur_node");
    ros::NodeHandle nh;
    std::string arg_msg;
    if (argc > 1)
    {
        arg_msg=argv[1];
    }
    else
    {
        arg_msg="No Argument - ";
    }
    CapteurPublisher capteur_publisher(&nh, arg_msg);
    ros::Timer timer = nh.createTimer(ros::Duration(0.1), &CapteurPublisher::timer_callback, &capteur_publisher);
    ros::spin();
    return 0;
}