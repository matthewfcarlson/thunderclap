#include "gen/global.h"

class CActorManager_2ed90 {
  public:
    void invoke(const char*);
};

template <> void Closure1<CActorManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2ed90 * *)&this->f_20)->*(*(void (CActorManager_2ed90::**)(const char *))&this->f_1c))(*b);
}
