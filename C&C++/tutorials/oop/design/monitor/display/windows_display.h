#ifndef _W_DISPLAY_IMPL_H_
#define _W_DISPLAY_IMPL_H_

#include "gui_display.h"

// windows
class WindowDisplayImpl : public GUIDisplayImpl {
 public:
  WindowDisplayImpl();
  ~WindowDisplayImpl();

  void drawPoint(int x, int y);
  void drawText(int x, int y, char text[]);
};

void WindowDisplayImpl::drawPoint(int x, int y) {
  // windows下的画点方式的具体实现...
}
void WindowDisplayImpl::drawText(int x, int y, char text[]) {
  // windows下的写字方式的具体实现...
}

// linux display
class LinuxDisplayImpl : public GUIDisplayImpl {
 public:
  LinuxDisplayImpl();
  ~LinuxDisplayImpl();

  void drawPoint(int x, int y);
  void drawText(int x, int y, char text[]);
};

void LinuxDisplayImpl::drawPoint(int x, int y) {
  // Linuxs下的画点方式的具体实现...
}
void LinuxDisplayImpl::drawText(int x, int y, char text[]) {
  // Linuxs下的写字方式的具体实现...
}

#endif