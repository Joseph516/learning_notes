#ifndef _LAYOUT_H_
#define _LAYOUT_H_

#include "gui_display.h"

// 不同的显示布局方式Layout1，Layout2....
class Layout1 : public GUIDisplay {
 public:
  Layout1(GUIDisplayImpl* impl)
      : GUIDisplay(impl) {}  // 用具体的GUI实现方式初始化
  void show(float load, long totalMemory, long usedMemory, long latency);
};

void Layout1::show(float load, long totalMemory, long usedMemory,
                   long latency) {
  // 具体布局实现
  drawLine(1, 2, 3, 4);
  drwaRect(1, 2, 3, 4);
}

#endif