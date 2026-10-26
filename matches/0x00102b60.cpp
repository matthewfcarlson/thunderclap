#include "compat/ptr.h"
#include "gen/global.h"

class Helper_102b60 {
  public:
    float f(int, int);
};
extern volatile const float gZero_102b60;

hulk_freg CMoveAgent::vfunc_3(hulk_intptr x, int y) {
    ((Helper_102b60*)this)->f(x, y);
    float z = gZero_102b60;
    *(int*)((char*)this + 8) = 0;
    return z;
}
