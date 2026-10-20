#include "gen/global.h"

extern "C" void _ReadWriteBarrier();
class CActorManager_2e980 {};
struct Arguments {
    const char* name;
    float value;
    const char* other;
};

template <> void Closure3<CActorManager, void, const char *, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; Arguments * args = (Arguments *)__p1; int unused2 = (int)__p2;

    const char* name = args->name;
    _ReadWriteBarrier();
    const char* other = args->other;
    float value = args->value;
    ((*(CActorManager_2e980 * *)&this->f_20)->*(*(void (CActorManager_2e980::**)(const char *, float, const char *))&this->f_1c))(name, value, other);
    _ReadWriteBarrier();
}
