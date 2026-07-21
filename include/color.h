#pragma once

#include <math/typedefs.h>

#include <cstdint>

struct Color {
  raster::Vec4f rgba;
  Color(float r, float g, float b, float a = 1.0f): rgba(r, g, b, a) {}
  Color(const raster::Vec4f& v): rgba(v) {}
  uint32_t pack() const;
  Color operator*(float t) const;
  Color operator+(const Color& other) const;
  Color lerp(const Color& other, float t) const;
};
