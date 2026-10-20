#include "gen/global.h"

class CEffectManager_1f7e90 {
  public:
    unsigned int FUN_001f7e90_callback(char*);
};

template <> void Closure1<CEffectManager, unsigned int, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { char ** argument = (char **)__p1; unsigned int * result = (unsigned int *)__p2;

    CEffectManager_1f7e90* m = (*(CEffectManager_1f7e90 * *)&this->f_20);
    unsigned int (CEffectManager_1f7e90::*fn)(char*) = (*(unsigned int (CEffectManager_1f7e90::**)(char *))&this->f_1c);
    unsigned int value = (m->*fn)(*argument);
    if (result)
        *result = value;
}
