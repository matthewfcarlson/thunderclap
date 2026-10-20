#include "gen/global.h"

struct CActorManager_2d800 {
    char unused;
};

template <> void Method4<CActorManager, void, const char *, float, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d800 * actor = (CActorManager_2d800 *)__p0; const char * args = (const char *)__p1;

    const char* name = *(const char**)args;
    args += 4;
    float value = *(float*)args;
    args += 4;
    int count = *(int*)args;
    args += 4;
    float other = *(float*)args;
    (actor->*(*(void (CActorManager_2d800::**)(const char *, float, int, float))&this->f_1c))(name, value, count, other);
}
