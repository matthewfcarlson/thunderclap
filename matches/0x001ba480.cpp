// Same code shape as 0x00030040 (propagated; names are from that function)
#include "gen/global.h"

class Actor_1ba480 {
  public:
    void fn(unsigned char);
};

template <> void Closure1<CRenderManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_1ba480 * *)&this->f_20)->*(*(void (Actor_1ba480::**)(unsigned char))&this->f_1c))(*arg);
}
