#ifndef _GUI_DISPLAY_H_
#define _GUI_DISPLAY_H_

#include "display.h"

// 新增GUI的显示抽象
class GUIDisplayImpl {
  int use;
  // 友元类的成员函数可以访问此类的包括非公有成员在内的所有成员
  // 如GUIDisplay的drawPOint
  friend class GUIDisplay;

 public:
  GUIDisplayImpl() : use(1) {}
  virtual ~GUIDisplayImpl();
  virtual void drawPoint(int x, int y) = 0;
  virtual void drawText(int x, int y, char text[]) = 0;
};

class GUIDisplay : public Display {
 private:
  GUIDisplayImpl* m_impl1;
  void drawPoint(int x, int y) { m_impl1->drawPoint(x, y); }
  void drawText(int x, int y, char text[]) { m_impl1->drawText(x, y, text); }

 public:
  GUIDisplay(GUIDisplayImpl* impl1) : m_impl1(impl1) {
    // 初始化列表中等价于: GUIDisplayImpl* impl1 = new WindowDisplayImpl;
  }
  ~GUIDisplay();

 protected:
  void drawLine(int x1, int y1, int x2, int y2);
  void drwaRect(int x1, int y1, int x2, int y2);
};

void GUIDisplay::drawLine(int x1, int y1, int x2, int y2) {
  // 通过drwaPoint实现
}

void GUIDisplay::drwaRect(int x1, int y1, int x2, int y2) {
  // 通过drawLine实现
}

#endif