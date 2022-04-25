#include "capteur_1/capteur.hpp"


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    std::string arg_msg;
    if (argc > 1)
    {
        arg_msg=argv[1];
    }
    else
    {
        arg_msg="No Argument - ";
    }
    rclcpp::spin(std::make_shared<CapteurPublisher>(arg_msg));
    rclcpp::shutdown();
    return 0;
}