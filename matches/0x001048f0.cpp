// Same code shape as 0x00102b60 (propagated; names are from that function)
#include "gen/global.h"

class Helper_1048f0 {
  public:
    float f(int, int);
};
extern volatile const float gZero_1048f0;

hulk_freg CPathAgent::vfunc_3(int x, int y) {
    ((Helper_1048f0*)this)->f(x, y);
    float z = gZero_1048f0;
    *(int*)((char*)this + 8) = 0;
    return z;
}
