#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

using namespace std::chrono_literals;

class CoordinatePublisher : public rclcpp::Node
{
public:
  CoordinatePublisher()
  : Node("coordinate_publisher"), count_(0)
  {
    // Inizializza il publisher sul topic "target_coordinates"
    publisher_ = this->create_publisher<geometry_msgs::msg::Point>("target_coordinates", 10);
    
    // Configura un timer per eseguire la callback a 10Hz (ogni 100ms)
    timer_ = this->create_wall_timer(
      100ms, std::bind(&CoordinatePublisher::timer_callback, this));
      
    RCLCPP_INFO(this->get_logger(), "Nodo Publisher avviato. Trasmissione a 10Hz.");
  }

private:
  void timer_callback()
  {
    auto message = geometry_msgs::msg::Point();
    // Simulazione di un percorso: incrementiamo le coordinate
    message.x = 10.0 + count_ * 0.1;
    message.y = 5.0 + count_ * 0.05;
    message.z = 20.0; // Altitudine costante per ora

    RCLCPP_INFO(this->get_logger(), "Pubblicazione Waypoint -> X: '%.2f', Y: '%.2f', Z: '%.2f'", 
                message.x, message.y, message.z);
                
    publisher_->publish(message);
    count_++;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CoordinatePublisher>());
  rclcpp::shutdown();
  return 0;
}