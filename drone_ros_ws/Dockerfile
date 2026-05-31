# Usa l'immagine base ufficiale ROS 2 (supporta nativamente ARM64)
FROM ros:humble

ENV DEBIAN_FRONTEND=noninteractive

# Impostiamo il display sul monitor virtuale che creeremo
ENV DISPLAY=:0
# Forziamo il rendering 3D sulla CPU in modo nativo dentro Linux
ENV LIBGL_ALWAYS_SOFTWARE=1
ENV GALLIUM_DRIVER=llvmpipe

# Installiamo ROS, Gazebo, i driver MESA e lo stack Web-VNC
RUN apt-get update && apt-get install -y \
    ros-humble-desktop \
    ros-humble-ros-gz \
    mesa-utils \
    xvfb \
    x11vnc \
    fluxbox \
    novnc \
    websockify \
    xterm \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /ros2_ws

# Setup dell'ambiente ROS
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "if [ -f /ros2_ws/install/setup.bash ]; then source /ros2_ws/install/setup.bash; fi" >> ~/.bashrc

# Il comando di avvio fa partire in background lo schermo virtuale, 
# il window manager, il server VNC e il bridge web, mantenendo poi bash aperto.
# Elimina eventuali file di lock rimasti da spegnimenti anomali, poi avvia lo stack
CMD ["sh", "-c", "rm -rf /tmp/.X* && Xvfb :0 -screen 0 1920x1080x24 & fluxbox & x11vnc -display :0 -forever -nopw -bg -xkb & websockify --web=/usr/share/novnc/ 8080 localhost:5900 & bash"]