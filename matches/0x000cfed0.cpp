#include "gen/global.h"

class HUDOverlay_cfed0 {
  public:
    void Call(unsigned char, float);
};

template <> void Closure2<HUDOverlay, void, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * args = (unsigned char *)__p1;

    ((*(HUDOverlay_cfed0 * *)&this->f_20)->*(*(void (HUDOverlay_cfed0::**)(unsigned char, float))&this->f_1c))(args[0], *(float*)(args + 4));
}
