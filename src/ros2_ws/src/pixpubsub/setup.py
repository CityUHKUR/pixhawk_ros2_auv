from setuptools import find_packages, setup

package_name = 'pixpubsub'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "main_sub = pixpubsub.pix_pubsub_node:main",
            "move_pub = pixpubsub.move_pub:main",
            "justmove_sub = pixpubsub.justmove_sub:main",
            "depth_pub = pixpubxub.testdepth_pub:main",
            "task_pub = pixpubxub.testtask_pub:main",
            "state_pub = pixpubxub.teststatem_pub:main"            
        ],
    },
)
