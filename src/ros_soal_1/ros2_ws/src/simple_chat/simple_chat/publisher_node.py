import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class Talker(Node):
    def __init__(self):
        super().__init__('talker_node')
        self.publisher = self.create_publisher(String, 'chat_topic', 10)
        self.timer = self.create_timer(1.0, self.publish_message)
        self.counter = 1

    def publish_message(self):
        msg = String()
        msg.data = f'Halo dari publisher, pesan ke-{self.counter}'
        self.publisher.publish(msg)
        self.get_logger().info(f'Publish: {msg.data}')
        self.counter += 1


def main(args=None):
    rclpy.init(args=args)
    node = Talker()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
