#include "formation_actions/client.hpp"


DummyActionClient::DummyActionClient(ros::NodeHandle* nh):
    nh_(*nh), client("go_to_point", true)
{
    sub_start_action_blocking = nh_.subscribe("start_blocking", 1, &DummyActionClient::action_blocking_callback, this);
    sub_start_action_non_blocking = nh_.subscribe("start_non_blocking", 1, &DummyActionClient::action_non_blocking_callback, this);
    sub_cancel = nh_.subscribe("cancel", 1, &DummyActionClient::action_cancel, this);

}

void DummyActionClient::action_blocking_callback(const std_msgs::EmptyConstPtr& msg)
{
    weez_u_msgs::GoToPointGoal goal;
    goal.point.msg = "New Goal - Blocking";
    ROS_INFO("Goal Blocking");
    client.sendGoalAndWait(goal); // Blocking

    ROS_INFO("Finished");
}

void DummyActionClient::action_non_blocking_callback(const std_msgs::EmptyConstPtr& msg)
{
    ROS_INFO("Send Goal - Non Blocking");
    weez_u_msgs::GoToPointGoal goal;
    goal.point.msg = "New Goal - Non Blocking";
    client.sendGoal(goal, boost::bind(&DummyActionClient::result_cb, this, _1, _2),
                boost::bind(&DummyActionClient::active_cb, this),
                boost::bind(&DummyActionClient::feedback_cb, this, _1));


}

void DummyActionClient::result_cb(const actionlib::SimpleClientGoalState& state, const weez_u_msgs::GoToPointResultConstPtr& result)
{
    ROS_INFO("Received Result");
    ROS_INFO_STREAM("Error code - " << result->error_code);
    ROS_INFO(result->msg.c_str());

}

void DummyActionClient::active_cb()
{
    ROS_INFO("Action got active");
}

void DummyActionClient::feedback_cb(const weez_u_msgs::GoToPointFeedbackConstPtr& feedback)
{
    ROS_INFO_STREAM("Receive Feedback - " << feedback->status);
}

void DummyActionClient::action_cancel(const std_msgs::EmptyConstPtr& msg)
{
    ROS_INFO("Cancelling");
    client.cancelAllGoals();
}



