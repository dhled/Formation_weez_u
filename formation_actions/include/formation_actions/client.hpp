#ifndef CLIENT_AC_HPP
#define CLIENT_AC_HPP

#include "ros/ros.h"
#include "weez_u_msgs/GoToPointAction.h"
#include <actionlib/client/simple_action_client.h>
#include "std_msgs/Empty.h"

#include <sstream>

class DummyActionClient
{
public:
    DummyActionClient(ros::NodeHandle* nh);
    ~DummyActionClient() {};

    //Action callback
    void result_cb(const actionlib::SimpleClientGoalState& state, const weez_u_msgs::GoToPointResultConstPtr& result);
    void feedback_cb(const weez_u_msgs::GoToPointFeedbackConstPtr& feeback);
    void active_cb();

    //Topic Subscriber Callback
    void action_blocking_callback(const std_msgs::EmptyConstPtr& msg);
    void action_non_blocking_callback(const std_msgs::EmptyConstPtr& msg);
    void action_cancel(const std_msgs::EmptyConstPtr& msg);

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_start_action_blocking;
    ros::Subscriber sub_start_action_non_blocking;
    ros::Subscriber sub_cancel;
    weez_u_msgs::MyPoint current_point;
    actionlib::SimpleActionClient<weez_u_msgs::GoToPointAction> client;

};

#endif