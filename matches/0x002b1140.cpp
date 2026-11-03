#include "gen/owners.h"
class C {
  public:
    void target(int);
};
void C::target(int x) {
    int y = 0;
    ((owners::Buffer_2b1010 *)this)->FUN_002b1010((unsigned int)x, &y);
}