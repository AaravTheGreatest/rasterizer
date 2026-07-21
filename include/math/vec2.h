#pragma once

namespace raster {
  template<typename T>
  struct Vec2 {
    T x, y;
    Vec2();
    Vec2(T x, T y);
    T dot(const Vec2<T>& other) const;
    Vec2<T> operator+(const Vec2<T>& other) const;
    Vec2<T> operator-(const Vec2<T>& other) const;
    Vec2<T> operator*(const Vec2<T>& other) const;
    Vec2<T> operator*(T s) const;
  };
  template<typename T>
  Vec2<T>::Vec2(): x(0), y(0) {}
  template<typename T>
  Vec2<T>::Vec2(T x, T y): x(x), y(y) {}
  template <typename T>
  T Vec2<T>::dot(const Vec2<T>& other) const { return (x * other.x + y * other.y); }
  template<typename T>
  Vec2<T> Vec2<T>::operator+(const Vec2<T>& other) const { return Vec2(x + other.x, y + other.y); }
  template<typename T>
  Vec2<T> Vec2<T>::operator-(const Vec2<T>& other) const { return Vec2(x - other.x, y - other.y); }
  template <typename T>
  Vec2<T> Vec2<T>::operator*(const Vec2<T>& other) const { return Vec2(x * other.x, y * other.y); }
  template <typename T>
  Vec2<T> Vec2<T>::operator*(T s) const { return Vec2(x * s, y * s); }
}
