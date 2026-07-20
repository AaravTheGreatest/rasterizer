#pragma once

#include <X11/Xlib.h>
#include <fb.h>

#include <vector>

int drawLine(Framebuffer& fb, int x1, int y1, int x2, int y2, uint32_t);
int drawTriangle(Framebuffer& fb, const int* verts, int startIndex, int numIndices);
int drawTriangle(Framebuffer& fb, int x1, int y1, int x2, int y2, int x3, int y3, bool filled, uint32_t color);
int drawTriangle(Framebuffer& fb, std::vector<int>& verts, int startIndex, int numIndices);


