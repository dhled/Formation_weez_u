#include "capteur_1/service_serveur.hpp"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "service_serveur_node");
    ros::NodeHandle nh;
    CapteurService capteur_service(&nh);
    ros::Timer timer = nh.createTimer(ros::Duration(0.1), &CapteurService::timer_callback, &capteur_service);
    ros::spin();
    return 0;
}