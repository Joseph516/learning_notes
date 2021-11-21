#include <string>

class Shape {
 public:
  typedef std::pair<float, float> Coordinate;

  Shape() = default;
  Shape(const std::string& name) : name_(name) {}
  virtual ~Shape() = default;
  virtual float area() const = 0;
  virtual float perimeter() const = 0;

 private:
  std::string name_;
};

// 长方形
class Rectangle : public Shape {
 public:
  Rectangle() = default;
  Rectangle(const std::string& name, const Coordinate& a, const Coordinate& b,
            const Coordinate& c, const Coordinate& d)
      : Shape(name), a_(a), b_(b), c_(c), d_(d) {}
  ~Rectangle() = default;

 protected:
  // 四个坐标点
  Coordinate a_, b_, c_, d_;
};

class Square : public Rectangle {
 public:
  Square() = default;
  Square(const std::string& name, const Coordinate& a, const Coordinate& b,
         const Coordinate& c, const Coordinate& d)
      : Rectangle(name, a, b, c, d) {}
  ~Square() = default;
};

class Circle : public Shape {
 public:
  Circle() = default;
  Circle(const std::string& name, const Coordinate& center)
      : Shape(name), center_(center) {}
  ~Circle() = default;

 private:
  Coordinate center_;
  float radius;
};
