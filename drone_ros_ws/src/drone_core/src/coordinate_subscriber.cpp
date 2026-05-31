#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

using std::placeholders::_1;

class CoordinateSubscriber : public rclcpp::Node
{
public:
  CoordinateSubscriber()
  : Node("coordinate_subscriber")
  {
    // Iscrizione al topic "target_coordinates". 
    // Quando arriva un dato, viene invocata la funzione topic_callback.
    subscription_ = this->create_subscription<geometry_msgs::msg::Point>(
      "target_coordinates", 10, std::bind(&CoordinateSubscriber::topic_callback, this, _1));
      
    RCLCPP_INFO(this->get_logger(), "Nodo Subscriber in ascolto...");
  }

private:
  void topic_callback(const geometry_msgs::msg::Point::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Waypoint Ricevuto -> X: '%.2f', Y: '%.2f', Z: '%.2f'", 
                msg->x, msg->y, msg->z);
  }

  rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CoordinateSubscriber>());
  rclcpp::shutdown();
  return 0;
}