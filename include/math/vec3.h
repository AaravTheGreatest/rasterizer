#pragma once

#include <math/vec2.h>

namespace raster {
  template<typename T>
  struct Vec3 {
    T x, y, z;
    Vec3();
    Vec3(T x, T y, T z);
    Vec3(const Vec2<T>& xy, T z);
    T dot(const Vec3<T>& other) const;
    Vec3<T> operator+(const Vec3<T>& other) const;
    Vec3<T> operator-(const Vec3<T>& other) const;
    Vec3<T> operator*(const Vec3<T>& other) const;
    Vec3<T> operator*(T s) const;
  };
  template<typename T>
  Vec3<T>::Vec3(): x(0), y(0), z(0) {}
  template<typename T>
  Vec3<T>::Vec3(T x, T y, T z): x(x), y(y), z(z) {}
  template<typename T>
  Vec3<T>::Vec3(const Vec2<T>& xy, T z): x(xy.x), y(xy.y), z(z) {}
  template <typename T>
  T Vec3<T>::dot(const Vec3<T>& other) const { return (x * other.x + y * other.y + z * other.z); }
  template<typename T>
  Vec3<T> Vec3<T>::operator+(const Vec3<T>& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
  template<typename T>
  Vec3<T> Vec3<T>::operator-(const Vec3<T>& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
  template <typename T>
  Vec3<T> Vec3<T>::operator*(const Vec3<T>& other) const { return Vec3(x * other.x, y * other.y, z * other.z); }
  template <typename T>
  Vec3<T> Vec3<T>::operator*(T s) const { return Vec3<T>(x * s, y * s, z * s); }
}
