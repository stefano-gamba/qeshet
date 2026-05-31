cmake_minimum_required(VERSION 3.8)
project(drone_core)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Trova le dipendenze necessarie
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Genera l'eseguibile del Publisher
add_executable(publisher_node src/coordinate_publisher.cpp)
ament_target_dependencies(publisher_node rclcpp geometry_msgs)

# Genera l'eseguibile del Subscriber
add_executable(subscriber_node src/coordinate_subscriber.cpp)
ament_target_dependencies(subscriber_node rclcpp geometry_msgs)

# Installa gli eseguibili nella directory di destinazione (fondamentale per ros2 run)
install(TARGETS
  publisher_node
  subscriber_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()