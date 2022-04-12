#ifndef SERVEUR_AC_HPP
#define SERVEUR_AC_HPP



#include "ros/ros.h"
#include "weez_u_msgs/GoToPointAction.h"
#include <actionlib/server/simple_action_server.h>

#include <sstream>

class DummyActionServeur
{
public:
    DummyActionServeur(ros::NodeHandle* nh);
    ~DummyActionServeur() {};

    void execute_callback(const weez_u_msgs::GoToPointGoalConstPtr &goal);

private:
    ros::NodeHandle nh_;
    actionlib::SimpleActionServer<weez_u_msgs::GoToPointAction> as_;
    weez_u_msgs::GoToPointFeedback feedback_;
    weez_u_msgs::GoToPointResult result_;
    
};

#endif