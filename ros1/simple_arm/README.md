# Description

Tutorial from the [Robotics Software Engineer Nanodegree by Udacity](https://www.udacity.com/course/robotics-software-engineer--nd209).

We are extending the `simple_arm` project by adding a couple of Nodes in C++. The goal was to explore:

- Publishers and Subscribers
- Request/Response and client/server architecture
- Defining custom messages and receiving messages

# Build instructions with Noetic

```bash
$ make build
$ make run
```

If you get any errors, you might want to make sure all the dependencies are installed.

```bash
$ cd catkin_ws/ && rosdep check simple_arm --ignore-src
```

# Resources

- [udacity/RoboND-simple_arm](https://github.com/udacity/RoboND-simple_arm)
