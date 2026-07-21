#pragma once

namespace raster {
  template<typename T>
  struct Vec4 {
    T x, y, z, w;
    Vec4();
    Vec4(T x, T y, T z, T w);
  };
  template<typename T>
  Vec4<T>::Vec4(): x(0), y(0), z(0), w(0) {}
  template<typename T>
  Vec4<T>::Vec4(T x, T y, T z, T w): x(x), y(y), z(z), w(w) {}
}
