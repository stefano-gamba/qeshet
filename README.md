# qeshet

## 🚀 Setup dell'Ambiente di Sviluppo (ROS 2 & Simulazione)

L'architettura del sistema robotico ("Sistema Nervoso") è basata su **ROS 2 Humble** e **Gazebo Ignition (Fortress)**. 

Per garantire la massima compatibilità cross-platform (inclusi macOS con chip Apple Silicon ARM64 e Windows) ed evitare complessi setup di X11 forwarding, l'intero ambiente grafico è containerizzato. L'interfaccia di Ubuntu, RViz2 e il simulatore Gazebo vengono renderizzati via software e resi disponibili direttamente tramite una comoda interfaccia Web (noVNC).

### Prerequisiti
* [Docker](https://www.docker.com/products/docker-desktop/) installato e in esecuzione.
* *Nota per utenti macOS/Windows:* Assicurarsi di aver allocato spazio sufficiente al disco virtuale di Docker (consigliati almeno 40GB) dalle impostazioni di Docker Desktop.

### 1. Avvio del Container ROS 2

Clona la repository e posizionati nella cartella principale. Avvia il container ROS 2 (il download e la prima compilazione richiederanno alcuni minuti):

```bash
# Avvia il container in background costruendo l'immagine
docker-compose up -d --build drone_ros
```

## Accesso alla Ground Control Station (Web GUI)

Una volta che il container è in esecuzione, l'ambiente desktop virtuale è immediatamente disponibile.
Apri il tuo browser (Chrome, Firefox, Safari) e vai all'indirizzo:

👉 http://localhost:8080/vnc.html

    Clicca su Connect (non è richiesta alcuna password).

    Fai clic destro in un punto qualsiasi dello schermo grigio per aprire il menu del window manager (Fluxbox).

    Seleziona Applications > Shells > Bash per aprire un terminale grafico.

    Da qui puoi lanciare i tool visivi come rviz2 o ign gazebo.