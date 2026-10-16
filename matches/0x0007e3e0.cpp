// Same code shape as 0x00030040 (propagated; names are from that function)
#include "gen/global.h"

class Actor_7e3e0 {
  public:
    void fn(unsigned char);
};

template <> void Closure1<CAmbientsManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_7e3e0 * *)&this->f_20)->*(*(void (Actor_7e3e0::**)(unsigned char))&this->f_1c))(*arg);
}
