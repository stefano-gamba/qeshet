# Usa l'immagine ufficiale ROS 2 Humble (Desktop include GUI tools)
FROM osrf/ros:humble-desktop

# Imposta la variabile d'ambiente per non bloccare apt durante le installazioni
ENV DEBIAN_FRONTEND=noninteractive

# Aggiorna il sistema e installa dipendenze utili
RUN apt-get update && apt-get install -y \
    x11-apps \
    git \
    wget \
    python3-pip \
    python3-colcon-common-extensions \
    ros-humble-gazebo-ros-pkgs \
    && rm -rf /var/lib/apt/lists/*

# Crea una directory per il workspace
WORKDIR /ros2_ws

# Assicurati che l'ambiente ROS venga caricato all'apertura di bash
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "if [ -f /ros2_ws/install/setup.bash ]; then source /ros2_ws/install/setup.bash; fi" >> ~/.bashrc

# Punto d'ingresso standard
CMD ["bash"]