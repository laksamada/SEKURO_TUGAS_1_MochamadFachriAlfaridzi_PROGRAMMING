# Penjelasan ROS2

## Struktur workspace

Workspace yang dibuat ada di `ros_soal_1/ros2_ws` dengan isi utama:

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

2. Build package:

```bash
colcon build
```

3. Source hasil build:

```bash
source install/setup.bash
```

## Cara menjalankan

Jalankan dua terminal.

Terminal 1:

```bash
cd src/ros_soal_1/ros2_ws
source install/setup.bash
ros2 run simple_chat talker
```

Terminal 2:

```bash
cd src/ros_soal_1/ros2_ws
source install/setup.bash
ros2 run simple_chat listener
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

Build package dengan `colcon build`, source workspace, jalankan publisher dan subscriber, lalu publisher mengirim pesan ke topic `chat_topic` dan subscriber membaca pesan itu secara realtime.
