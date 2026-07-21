#pragma once

#include <math/vec3.h>

namespace raster {
  template<typename T>
  struct Vec4 {
    T x, y, z, w;
    Vec4();
    Vec4(T x, T y, T z, T w);
    Vec4(const Vec3<T>& xyz, T w = 1);
    Vec4(const Vec2<T>& xy, T z, T w = 1);
    T dot(const Vec4<T>& other) const;
    Vec4<T> operator+(const Vec4<T>& other) const;
    Vec4<T> operator-(const Vec4<T>& other) const;
    Vec4<T> operator*(const Vec4<T>& other) const;
    Vec4<T> operator*(T s) const;
  };
  template<typename T>
  Vec4<T>::Vec4(): x(0), y(0), z(0), w(1) {}
  template<typename T>
  Vec4<T>::Vec4(T x, T y, T z, T w): x(x), y(y), z(z), w(w) {}
  template<typename T>
  Vec4<T>::Vec4(const Vec3<T>& xyz, T w): x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
  template<typename T>
  Vec4<T>::Vec4(const Vec2<T>& xy, T z, T w): x(xy.x), y(xy.y), z(z), w(w) {}
  template <typename T>
  T Vec4<T>::dot(const Vec4<T>& other) const { return (x * other.x + y * other.y + z * other.z + w * other.w); }
  template<typename T>
  Vec4<T> Vec4<T>::operator+(const Vec4<T>& other) const { return Vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
  template<typename T>
  Vec4<T> Vec4<T>::operator-(const Vec4<T>& other) const { return Vec4(x - other.x, y - other.y, z - other.z, w - other.w); }
  template <typename T>
  Vec4<T> Vec4<T>::operator*(const Vec4<T>& other) const { return Vec4(x * other.x, y * other.y, z * other.z, w * other.w); }
  template <typename T>
  Vec4<T> Vec4<T>::operator*(T s) const { return Vec4<T>(x * s, y * s, z * s, w * s); }
}
