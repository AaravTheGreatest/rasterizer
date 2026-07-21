#include <draw.h>
#include <fb.h>
#include <math.h>
#include <colors.h>

#include <SFML/Graphics.hpp>

#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

int main() {
  constexpr int width = 800;
  constexpr int height = 600;
  sf::RenderWindow window(sf::VideoMode({width, height}), "Rasterizer");
  Framebuffer framebuffer(width, height);
  sf::Texture texture({width, height});
  sf::Sprite sprite(texture);
  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) window.close();
      if (event->is<sf::Event::KeyPressed>()) {
        auto key = event->getIf<sf::Event::KeyPressed>();
        if (key->code == sf::Keyboard::Key::Escape || key->code == sf::Keyboard::Key::Q) window.close();
      }
    }
    framebuffer.clear(Colors::Black.pack());
    drawTriangle(framebuffer, 100, 100, 200, 10, 200, 100, true, Colors::Green.pack());
    texture.update(reinterpret_cast<const uint8_t*>(framebuffer.data()));
    window.clear();
    window.draw(sprite);
    window.display();
  }
}
