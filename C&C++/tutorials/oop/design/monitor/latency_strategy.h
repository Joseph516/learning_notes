class LatencyStrategy {
 public:
  virtual long getNetworkLatency() = 0;
};

class LatencyStrategyImpl1 : public LatencyStrategy {
 public:
  long getNetworkLatency() {
    long latency;
    // get latency here
    return latency;
  }
};