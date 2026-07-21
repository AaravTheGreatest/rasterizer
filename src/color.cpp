#include <color.h>

uint32_t Color::pack() const {
  return ((int)(rgba.w * 255) << 24) | ((int)(rgba.x * 255) << 16) | ((int)(rgba.y * 255) << 8) | (int)(rgba.z * 255);
}
Color Color::operator*(float t) const {
  return Color(rgba.x * t, rgba.y * t, rgba.z * t, rgba.w * t);
}
Color Color::operator+(const Color& other) const {
  return Color(rgba + other.rgba);
}
Color Color::lerp(const Color& other, float t) const {
  return (*this) * (1.0f - t) + other * t;
}
