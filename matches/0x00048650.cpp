#include "gen/global.h"

class Helper_48650 {
  public:
    Helper_48650* first();
    int second();
};

void CAxisCondition::vfunc_8(int arg) {
    Helper_48650* h = ((Helper_48650*)arg)->first();
    int v = h->second();
    vfunc_9(v, v + this->f_0c * 0x38 + 0x1ff4);
}
