# rasterizer

A simple software rasterizer written from scratch in C++.  
Supports 2D primitive shapes with a custom X11 framebuffer.  
Plan to implement 3D rendering and support for Wayland as well in the future  

## Current features

- X11 output using XImages from a custom framebuffer  
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
- X11 development libraries  

Clone repo:  

```bash
git clone https://github.com/AaravTheGreatest/rasterizer.git
```

Build:  

```bash
cd rasterizer && make
```

Run:  

```bash
./build/main
```
