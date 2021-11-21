/**
 * 负载监视器的面向对象设计
 * 要求：
 * 1.
 * 监视计算节点的负载状态，如CPU占有率（不同版本的OS获取CPU占有率的方式不同）。
 */
#include "monitor.h"

int main(int argc, char *argv[]) {
  LoadStrategyImpl1 loadStrategy;
  MemoryStrategyImpl1 memoryStrategy;
  LatencyStrategyImpl1 latencyStrategy;
  
  WindowDisplayImpl impl; // windows GUI
  Layout1 display(&impl); // 布局1显示

  Monitor monitor(&loadStrategy, &memoryStrategy, &latencyStrategy, &display);

  while (true) {
    monitor.getLoad();
    monitor.getTotalMemory();
    monitor.getUseMemory();
    monitor.getNetworkLatency();

    monitor.show();
    // sleep(1000);
  }
}