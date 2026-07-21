#pragma once

namespace raster {
  template<typename T>
  struct Vec3 {
    T x, y, z;
    Vec3();
    Vec3(T x, T y, T z);
  };
  template<typename T>
  Vec3<T>::Vec3(): x(0), y(0), z(0) {}
  template<typename T>
  Vec3<T>::Vec3(T x, T y, T z): x(x), y(y), z(z) {}
}
