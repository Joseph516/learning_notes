#include <string>

class Person {
 private:
  std::string name;
  std::string addr;

 public:
  std::string const& get_name() const { return name; }
  std::string const& get_addr() const { return addr; }
};