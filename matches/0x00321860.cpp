#include "compat/ptr.h"
#include "gen/pure3d.h"

struct d3dContext_nv_321860 {
    void fix();
};
class Worker_321860 {
  public:
    int run(int, int, hulk_intptr, int, int);
};

int pure3d::d3dContext::vfunc_30(hulk_intptr a, int b, int c, int d, int e) {
    if (!a)
        a = this->f_160;
    if (this->f_414)
        ((d3dContext_nv_321860*)this)->fix();
    ((Worker_321860*)this->f_204)->run(b, c, a, d, e);
    return this->f_204;
}
