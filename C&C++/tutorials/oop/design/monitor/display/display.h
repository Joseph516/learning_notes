#ifndef _DISPLAY_H_
#define _DISPLAY_H_

class Display {
 public:
  Display();
  virtual ~Display();
  virtual void show(float load, long totalMemory, long usedMemory,
                    long latency) = 0;
};

/*
class WindowsDisplay : public Display {
 public:
  void show(float load, long totalMemory, long usedMemory, long latency) {
    // display...
  }
};

class ConsoleDisplay : public Display {
 public:
  void show(float load, long totalMemory, long usedMemory, long latency){
      // display...
  };
};
*/

#endif
