#include <color.h>

uint32_t Color::pack() const {
  return (a * 255 << 24) | (r * 255 << 16) | (g * 255 << 8) | b * 255;
}
Color Color::operator*(float t) const {
  return Color(r * t, g * t, b * t, a);
}
Color Color::operator+(const Color& other) const {
  return Color(r + other.r, g + other.g, b + other.b, a + other.a);
}
