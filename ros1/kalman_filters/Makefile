TARGETS := build run clean help
.PHONY: $(TARGETS)

CMAKE_OPTIONS := -DEIGEN_BUILD_PKGCONFIG=OFF -DEIGEN_BUILD_DOC=OFF -DBUILD_TESTING=OFF -Wno-dev

build:
	@cmake -B _build $(CMAKE_OPTIONS)
	@cd _build && make
	@ln -sf _build/compile_commands.json compile_commands.json

run: build
	@./_build/kalman

clean:
	-@rm -fr _build
	-@rm compile_commands.json

help:
	@echo "make [ $(TARGETS) ]"
