# Description

Tutorial from the [Robotics Software Engineer Nanodegree by Udacity](https://www.udacity.com/course/robotics-software-engineer--nd209).

We are extending the `simple_arm` project by adding a couple of Nodes in C++. The goal was to explore:
- Publishers and Subscribers
- Request/Response and client/server architecture
- Defining custom messages and receiving messages

# Build instructions with Noetic

```bash
$ cd simple_arm/catkin_ws && catkin_init_workspace
$ source devel/setup.[bash|zsh]

# Install dependencies
$ rosdep check simple_arm --ignore-src
$ rosdep install simple_arm --ignore-src

# Build
$ catkin_make

# Run
$ roslaunch simple_arm robot_spawn.launch
```

# Resources

- [udacity/RoboND-simple_arm](https://github.com/udacity/RoboND-simple_arm)
