#include "formation_actions/serveur.hpp"


DummyActionServeur::DummyActionServeur(ros::NodeHandle* nh):
    nh_(*nh), as_(*nh, "go_to_point", boost::bind(&DummyActionServeur::execute_callback, this, _1), false)
{
    as_.start();

}

void DummyActionServeur::execute_callback(const weez_u_msgs::GoToPointGoalConstPtr &goal)
{
    ros::Rate r(1);
    bool success = true;
    
    std::stringstream ss;
    ss << "Goal Received - " << goal->point.msg;
    ROS_INFO(ss.str().c_str());
    
    for(int count=0; count<10; count++)
    {
        if (as_.isPreemptRequested() || !ros::ok())
        {
            ROS_INFO("Canceled !");
            success = false;
            break;
        }
        ss.str("");
        ss << "Count - " << count;
        feedback_.status = ss.str();
        feedback_.header.stamp = ros::Time::now();
        as_.publishFeedback(feedback_);
        r.sleep();
    }

    if(success)
    {
        result_.error_code = 0;
        result_.msg = "Success";
        as_.setSucceeded(result_);
    }
    else
    {
        result_.error_code = weez_u_msgs::GoToPointResult::FAILURE;
        result_.msg = "Failure";
        as_.setPreempted(result_);
        
    }
    
    

}

