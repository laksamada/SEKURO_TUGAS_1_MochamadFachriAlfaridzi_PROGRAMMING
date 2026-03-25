from setuptools import find_packages, setup

package_name = 'simple_chat'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='cakru',
    maintainer_email='cakru@example.com',
    description='Simple ROS2 publisher subscriber package',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'talker = simple_chat.publisher_node:main',
            'listener = simple_chat.subscriber_node:main',
        ],
    },
)
