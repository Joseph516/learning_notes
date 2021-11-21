class LoadStrategy {
 public:
  virtual float getLoad() = 0;
};

class LoadStrategyImpl1 : public LoadStrategy {
 public:
  float getLoad() {
    float load;
    // get load here
    return load;
  }
};

class LoadStrategyImpl2 : public LoadStrategy {
 public:
  float getLoad() {
    float load;
    // get load here
    return load;
  }
};