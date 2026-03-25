# Penjelasan ROS2

## Struktur workspace

Workspace yang dibuat ada di folder `src/ros_soal_1/ros2_ws` dengan isi utama:

- `src/simple_chat/package.xml`
- `src/simple_chat/setup.py`
- `src/simple_chat/setup.cfg`
- `src/simple_chat/resource/simple_chat`
- `src/simple_chat/simple_chat/publisher_node.py`
- `src/simple_chat/simple_chat/subscriber_node.py`

Package yang dipakai bernama `simple_chat` dan memakai `ament_python`.

## Cara build

1. Masuk ke workspace:

```bash
cd src/ros_soal_1/ros2_ws
```

2. Aktifkan environment ROS2:

```bash
micromamba activate ros_env
```

3. Build package:

```bash
colcon build
```

4. Source hasil build:

```bash
source install/local_setup.bash
```

## Cara menjalankan

Jalankan dua terminal.

Terminal 1:

```bash
cd src/ros_soal_1/ros2_ws
micromamba activate ros_env
source install/local_setup.bash
ros2 run simple_chat listener
```

Terminal 2:

```bash
cd src/ros_soal_1/ros2_ws
micromamba activate ros_env
source install/local_setup.bash
ros2 run simple_chat talker
```

## Cara kerja program

Node publisher bernama `talker_node`.
Node ini mengirim pesan string ke topic `chat_topic` setiap 1 detik.

Node subscriber bernama `listener_node`.
Node ini subscribe ke topic `chat_topic` lalu menampilkan isi pesan yang diterima.

Isi pesan yang dikirim berbentuk:

```text
Halo dari publisher, pesan ke-1
Halo dari publisher, pesan ke-2
Halo dari publisher, pesan ke-3
```

## Node dan topic

Untuk melihat node yang aktif:

```bash
ros2 node list
```

Hasilnya akan memunculkan:

```text
/listener_node
/talker_node
```

Untuk melihat topic yang aktif:

```bash
ros2 topic list
```

Salah satu topic yang muncul:

```text
/chat_topic
```

Untuk melihat tipe pesan topic:

```bash
ros2 topic info /chat_topic
```

Topic `chat_topic` memakai tipe `std_msgs/msg/String`.

Untuk melihat isi pesan secara langsung:

```bash
ros2 topic echo /chat_topic
```

## Alur singkat

Masuk ke workspace, aktifkan environment ROS2, jalankan `colcon build`, lalu `source install/local_setup.bash`. Setelah itu node `talker_node` mengirim pesan ke topic `chat_topic` dan node `listener_node` membaca pesan tersebut secara realtime.
