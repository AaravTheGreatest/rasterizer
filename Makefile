CXX = g++
CXXFLAGS = -Iinclude
LDLIBS = -lX11

SRC = src/fb.cpp src/draw.cpp

all: build
	$(CXX) -o build/main src/*.cpp $(CXXFLAGS) $(LDLIBS)

EXAMPLE ?= rect

example: build
	$(CXX) -o build/$(EXAMPLE) examples/$(EXAMPLE).cpp $(SRC) $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf build/*

build:
	mkdir -p build

.PHONY: all example clean build
