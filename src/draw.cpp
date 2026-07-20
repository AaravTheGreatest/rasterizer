#include <draw.h>

#include <algorithm>
#include <cmath>

int edge(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
}

int drawLine(Framebuffer& fb, int x1, int y1, int x2, int y2, uint32_t color) {
  int dx = (x2 - x1), dy = (y2 - y1);
  if (dx == 0 && dy == 0) {
    fb.setPixel(x1, y1, color);
  }
  else {
    int steps = std::max(std::abs(dx), std::abs(dy));
    float xInc = (float)dx / steps, yInc = (float)dy / steps;
    float x = (float)x1, y = (float)y1;
    for (int i = 0; i <= steps; i++) {
      fb.setPixel(std::round(x), std::round(y), color);
      x += xInc; y += yInc;
    }
  }
  return 0;
}
int drawTriangle(Framebuffer& fb, int x1, int y1, int x2, int y2, int x3, int y3, bool filled, uint32_t color) {
  drawLine(fb, x1, y1, x2, y2, color); drawLine(fb, x2, y2, x3, y3, color); drawLine(fb, x3, y3, x1, y1, color);
  if (filled) {
    int xMin = std::min(x1, std::min(x2, x3)), xMax = std::max(x1, std::max(x2, x3)),
        yMin = std::min(y1, std::min(y2, y3)), yMax = std::max(y1, std::max(y2, y3));
    for (int y = yMin; y <= yMax; y++) {
      for (int x = xMin; x <= xMax; x++){
        int p1 = edge(x1, y1, x2, y2, x, y),
            p2 = edge(x2, y2, x3, y3, x, y),
            p3 = edge(x3, y3, x1, y1, x, y);
        if ((p1 >= 0 && p2 >= 0 && p3 >= 0) || (p1 <= 0 && p2 <= 0 && p3 <= 0)) fb.setPixel(x, y, color);
      }
    }
  }
  return 0;
}
int drawTriangle(Framebuffer& fb, const int* verts, int startIndex, int numIndices) {
  return 0;
}
int drawTriangle(Framebuffer& fb, std::vector<int>& verts, int startIndex, int numIndices) {
  return 0;
}

