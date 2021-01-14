TARGETS := build run clean help

build:
	@cmake -B _build
	@cd _build && make
	@ln -sf _build/compile_commands.json compile_commands.json

run: build
	@./_build/kalman

clean:
	-@rm -fr _build
	-@rm compile_commands.json

help:
	@echo "make [ $(TARGETS) ]"
