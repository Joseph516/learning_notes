#include "monitor.h"

Monitor::Monitor(LoadStrategy* loadStrategy, MemoryStrategy* memoryStrategy,
                 LatencyStrategy* latencyStrategy, Display* display)
    : m_loadStrategy(loadStrategy),
      m_memoryStrategy(memoryStrategy),
      m_latencyStrategy(latencyStrategy),
      m_display(display),
      load(0),
      totalMemory(0),
      usedMemory(0),
      latency(0) {}

void Monitor::show() {
  m_display->show(load, totalMemory, usedMemory, latency);
}

void Monitor::getLoad() { m_loadStrategy->getLoad(); }

void Monitor::getTotalMemory() { m_memoryStrategy->getTotal(); }

void Monitor::getUseMemory() { m_memoryStrategy->getUsed(); }

void Monitor::getNetworkLatency() { m_latencyStrategy->getNetworkLatency(); }