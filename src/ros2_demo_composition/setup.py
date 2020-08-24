from setuptools import setup

package_name = 'ros2_demo_composition'

setup(
    name=package_name,
    version='0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    author='Kenneth De Leener',
    author_email='kenneth.de-leener@cnhind.com',
    maintainer='Kenneth De Leener',
    maintainer_email='kenneth.de-leener@cnhind.com',
    keywords=['ROS'],
    classifiers=[
        'Intended Audience :: Developers',
        'Programming Language :: Python',
        'Topic :: sensorFusion',
    ],
    description='Subscriber to sensor fusion messages',
    # license='Apache License, Version 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'demo_composition ='
            ' ros2_demo_composition.ros2_demo_composition:main',
        ],
    },
)
