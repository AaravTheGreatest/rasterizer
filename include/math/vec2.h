#pragma once

namespace raster {
  template<typename T>
  struct Vec2 {
    T x, y;
    Vec2();
    Vec2(T x, T y);
  };
  template<typename T>
  Vec2<T>::Vec2(): x(0), y(0) {}
  template<typename T>
  Vec2<T>::Vec2(T x, T y): x(x), y(y) {}
}
