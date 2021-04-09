class MemoryStrategy {
 public:
  virtual long getTotal() = 0;
  virtual long getUsed() = 0;
};

class MemoryStrategyImpl1 : public MemoryStrategy {
 public:
  long getTotal() {
    long total;
    // get total memory here
    return total;
  }
  long getUsed() {
    long used;
    // get used memory here
    return used;
  }
};

class MemoryStrategyImpl2 : public MemoryStrategy {
 public:
  long getTotal() {
    long total;
    // get total memory here
    return total;
  }
  long getUsed() {
    long used;
    // get used memory here
    return used;
  }
};