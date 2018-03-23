#include "rclcpp/rclcpp.hpp"
#include <chrono>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("iterativo");

    int count=0;

    rclcpp::WallRate loop_rate(50ms);

    while (rclcpp::ok())
    {
        RCLCPP_INFO(node->get_logger(), "iteration %d", count++);

        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();

    return 0;

 }
