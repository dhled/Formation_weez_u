#include "formation_actions/serveur.hpp"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "action_serveur_node");
    ros::NodeHandle nh;
    DummyActionServeur action_serveur(&nh);
    ros::spin();
    return 0;
}