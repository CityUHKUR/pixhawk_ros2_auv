from setuptools import find_packages
from setuptools import setup

setup(
    name='pioneer_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('pioneer_msgs', 'pioneer_msgs.*')),
)
