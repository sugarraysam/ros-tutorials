TARGETS := build run help
.PHONY: $(TARGETS)

export SHELL := /bin/bash

build:
	@cd catkin_ws && source ./devel/setup.bash && catkin_make
	@ln -sf catkin_ws/build/compile_commands.json compile_commands.json

run: build
	@cd catkin_ws && source ./devel/setup.bash && roslaunch simple_arm robot_spawn.launch

help:
	@echo "make [ $(TARGETS) ]"
