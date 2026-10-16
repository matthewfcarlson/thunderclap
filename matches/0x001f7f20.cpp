#include "gen/global.h"

struct CEffectManager_1f7f20 {
    bool run(bool);
};

template <> void Closure1<CEffectManager, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; bool * arg = (bool *)__p1; bool * out = (bool *)__p2;

    CEffectManager_1f7f20* o = (*(CEffectManager_1f7f20 * *)&this->f_20);
    bool b = *arg;
    bool (CEffectManager_1f7f20::*f)(bool) = (*(bool (CEffectManager_1f7f20::**)(bool))&this->f_1c);
    bool value = (o->*f)(b);
    if (out)
        *out = value;
}
