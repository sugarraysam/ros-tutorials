TARGETS := build launch help
.PHONY: $(TARGETS)

export SHELL := /bin/bash

build:
	@catkin_make
	@ln -sf build/compile_commands.json compile_commands.json

launch: build
	@source ./devel/setup.bash && roslaunch simple_arm robot_spawn.launch

help:
	@echo "make [ $(TARGETS) ]"
