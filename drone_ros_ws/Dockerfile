# Usa l'immagine base ufficiale ROS 2 (supporta nativamente ARM64)
FROM ros:humble

ENV DEBIAN_FRONTEND=noninteractive

# Installiamo ROS 2 Desktop e il nuovo Gazebo (Ignition Fortress)
RUN apt-get update && apt-get install -y \
    ros-humble-desktop \
    x11-apps \
    git \
    wget \
    python3-pip \
    python3-colcon-common-extensions \
    ros-humble-ros-gz \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /ros2_ws

RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "if [ -f /ros2_ws/install/setup.bash ]; then source /ros2_ws/install/setup.bash; fi" >> ~/.bashrc

CMD ["bash"]