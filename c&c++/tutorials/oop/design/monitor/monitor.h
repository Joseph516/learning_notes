#ifndef _MONITOR_H_
#define _MONITOR_H_

#include "display/display.h"
#include "display/gui_display.h"
#include "display/layout.h"
#include "display/windows_display.h"
#include "latency_strategy.h"
#include "load_strategy.h"
#include "memory_strategy.h"

class Monitor {
 private:
  LoadStrategy* m_loadStrategy;
  MemoryStrategy* m_memoryStrategy;
  LatencyStrategy* m_latencyStrategy;
  float load, latency;
  long totalMemory, usedMemory;
  Display* m_display;

 public:
  Monitor(LoadStrategy* loadStrategy, MemoryStrategy* memoryStrategy,
          LatencyStrategy* latencyStrategy, Display* display);
  // 根据策略获得显示参数
  void getLoad();
  void getTotalMemory();
  void getUseMemory();
  void getNetworkLatency();
  
  // 显示CPU参数到GUI或console
  void show();

  // 设置不同的策略
  void setLoadStrategy(LoadStrategy* loadStrategy);
  void setMemoryStrategyy(MemoryStrategy* memoryStrategy);
  void setLatencyStrategyy(LatencyStrategy* latencyStrategy);
};

#endif