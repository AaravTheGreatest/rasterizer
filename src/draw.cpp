#include <draw.h>

int drawTriangle(Display* display, int screen, Window& window, const int* verts, int startIndex, int numIndices) {
  if (!((sizeof(verts)/sizeof(int)) - (startIndex + numIndices) > -1)) return -1;

}
int drawTriangle(Display* display, int screen, Window& window, int x1, int y1, int x2, int y2, int x3, int y3) {

}
int drawTriangle(Display* display, int screen, Window& window, std::vector<int>& verts, int startIndex, int numIndices);

