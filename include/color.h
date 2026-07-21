#pragma once

#include <cstdint>

struct Color {
  uint32_t r, g, b, a;
  Color(float r, float g, float b, float a = 255): a(a), r(r), g(g), b(b) {}
  uint32_t pack() const;
  Color operator*(float t) const;
  Color operator+(const Color& other) const;
};
