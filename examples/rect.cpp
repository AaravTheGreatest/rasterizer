#include <draw.h>
#include <fb.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#include <chrono>
#include <thread>
#include <stdio.h>

void updateScreen(Display* display, Window window, XImage* image, Framebuffer& fb) {
  XPutImage(
      display,
      window,
      DefaultGC(display, DefaultScreen(display)),
      image,
      0, 0,
      0, 0,
      fb.getWidth(),
      fb.getHeight()
    );
    XFlush(display);
}

int main() {
  Display* display = XOpenDisplay(nullptr);
  int screen = DefaultScreen(display), fps = 60;
  Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 50, 50, 600, 800, 2, BlackPixel(display, screen),WhitePixel(display, screen));
  Framebuffer framebuffer(600, 800);
  XImage* image = XCreateImage(
    display,
    DefaultVisual(display, screen),
    24,
    ZPixmap,
    0,
    reinterpret_cast<char*>(framebuffer.data()),
    framebuffer.getWidth(),
    framebuffer.getHeight(),
    32,
    framebuffer.getWidth() * sizeof(uint32_t)
  );
  bool running = true;
  XSelectInput(display, window, KeyPressMask | StructureNotifyMask | ExposureMask);
  XMapWindow(display, window);
  while (running) {
    while (XPending(display)) {
      XEvent event;
      XNextEvent(display, &event);
      switch (event.type) {
        case KeyPress: {
                         XKeyEvent* key = &event.xkey;
                         KeySym keysym = XLookupKeysym(key, 0);
                         if (keysym == XK_Escape) running = false;
                         if (keysym == XK_Q || keysym == XK_q) running = false;
                         printf("Key pressed: %lu\n", keysym);
                         break;
        }
        case DestroyNotify: {
                              running = false;
                              break;
        }
        case ConfigureNotify: {
                                XConfigureEvent* config = &event.xconfigure;
                                framebuffer.setWidth(config->width);
                                framebuffer.setHeight(config->height);
                                if (image) {
                                  image->data = nullptr;
                                  XDestroyImage(image);
                                }
                                image = XCreateImage(
                                  display,
                                  DefaultVisual(display, screen),
                                  24,
                                  ZPixmap,
                                  0,
                                  reinterpret_cast<char*>(framebuffer.data()),
                                  framebuffer.getWidth(),
                                  framebuffer.getHeight(),
                                  32,
                                  framebuffer.getWidth() * sizeof(uint32_t)
                                );

                                printf("Resize: %dx%d\n", config->width, config->height);
                                break;
        }
        case Expose: {
                       updateScreen(display, window, image, framebuffer);
                       break;
        }
      }
    }
    framebuffer.clear(0xFF000000);
    drawTriangle(framebuffer, 100, 100, 200, 10, 200, 100, true, 0xFFFFFFFF);
    drawTriangle(framebuffer, 100, 100, 100, 10, 200, 10, true, 0xFF0000FF);
    updateScreen(display, window, image, framebuffer);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
  }
}
