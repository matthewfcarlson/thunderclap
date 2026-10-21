#include "compat/ptr.h"
class Thing {
  public:
    char pad[8];
    int value;
    float helper(int, int);
    hulk_freg run(int x);
};
hulk_freg Thing::run(int x) {
    return helper(x, value);
}
