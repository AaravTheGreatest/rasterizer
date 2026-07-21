# rasterizer

A simple software rasterizer written from scratch in C++.  
Supports 2D primitive shapes with a custom framebuffer.  
Plan to implement 3D rendering in the future  

## Current features

- Graphical output from a custom framebuffer  
- SFML window creation to allow compatibility with any OS  
- Keyboard and window events (keysym from X11)  
- Dynamic resizing of the framebuffer based on window size  
- Line drawing  
- Wireframe & filled triangle rasterization  

## Todo

- 3D rendering & transformations  
- Projection  
- Mesh loading (like .obj files)  
- Depth buffer (Z-buffer) for 3D rendering  
- Textures  
- Lighting  

## Build instructions

Requires:

- `make`  
- C++ compiler  
- Either SFML-3.x or X11 development libraries  
Clone repo:  

```bash
git clone https://github.com/AaravTheGreatest/rasterizer.git
```

Build:  

To build a specific example (`cat rasterizer/examples` to see all examples):  

```bash
cd rasterizer && make example EXAMPLE=name
```

For example, `make example EXAMPLE=rect` would build examples/rect.cpp

`make example` defaults to rect.cpp  

For SFML examples, run `make sfml`  

Run:  

```bash
./build/main
```
