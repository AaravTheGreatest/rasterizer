CXX = g++
CXXFLAGS = -Iinclude
LDLIBS = -lX11

SRC = src/fb.cpp src/draw.cpp src/color.cpp

all: build
	$(CXX) -o build/main src/*.cpp $(CXXFLAGS) $(LDLIBS)

EXAMPLE ?= rect

example: build
	$(CXX) -o build/$(EXAMPLE) examples/$(EXAMPLE).cpp $(SRC) $(CXXFLAGS) $(LDLIBS)

sfml:
	$(CXX) -o build/sfmlTriangle examples/sfml/triangle.cpp $(SRC) $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf build/*

build:
	mkdir -p build

.PHONY: all example clean build
