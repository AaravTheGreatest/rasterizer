#pragma once

#include <X11/Xlib.h>
#include <fb.h>

#include <vector>

int drawTriangle(Display* display, int screen, Window& window, const int* verts, int startIndex, int numIndices);
int drawTriangle(Display* display, int screen, Window& window, int x1, int y1, int x2, int y2, int x3, int y3);
int drawTriangle(Display* display, int screen, Window& window, std::vector<int>& verts, int startIndex, int numIndices);


