#include <iostream>

#include "smartpointer.h"
#include "csmartpointer.h"

class Widget
{
public:
  int version;
};

int main (int argc, char * const argv[]) {
  // s_ptr<Widget> sp(new Widget);
  // s_ptr<Widget> sp2(new Widget);
  // sp -> version = 0;
  // sp2 = sp;
  // sp2 -> version = 1;
  // std::cout << sp2 -> version << std::endl;
  // std::cout << sp -> version << std::endl;
  c_ptr<Widget> cp(new Widget);
  cp->version = 0;
  std::cout << cp->version << std::endl;
  c_ptr<Widget> cp2(cp);
  cp2->version = 1;
  std::cout << cp->version << std::endl;
  return 0;
}