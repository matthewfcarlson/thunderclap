#include "gen/global.h"

class Actor_30040 {
  public:
    void fn(unsigned char);
};

template <> void Closure1<CActorManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_30040 * *)&this->f_20)->*(*(void (Actor_30040::**)(unsigned char))&this->f_1c))(*arg);
}
