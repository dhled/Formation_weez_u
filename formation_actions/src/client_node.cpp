#include "formation_actions/client.hpp"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "service_serveur_node");
    ros::NodeHandle nh;
    DummyActionClient dummy_action_client(&nh);
    ros::spin();
    return 0;
}