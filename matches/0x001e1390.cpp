// Same code shape as 0x0002ed90 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1e1390 {
  public:
    void invoke(const char*);
};

template <> void Closure1<CSPManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1e1390 * *)&this->f_20)->*(*(void (CActorManager_1e1390::**)(const char *))&this->f_1c))(*b);
}
