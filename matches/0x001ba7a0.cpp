#include "gen/global.h"

struct CRenderManager_1ba7a0 {
    unsigned int run(unsigned int, const char*, float, float);
};

template <> void Closure4<CRenderManager, unsigned int, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * p = (void *)__p1; void * out = (void *)__p2;

    CRenderManager_1ba7a0* o = (*(CRenderManager_1ba7a0 * *)&this->f_20);
    unsigned int (CRenderManager_1ba7a0::*fn)(unsigned int, const char*, float, float) = (*(unsigned int (CRenderManager_1ba7a0::**)(unsigned int, const char *, float, float))&this->f_1c);
    unsigned int* a = (unsigned int*)p;
    unsigned int id = *a++;
    const char* volatile name = (const char*)*a++;
    float first = *(float*)a++;
    float second = *(float*)a++;
    unsigned int value = (o->*fn)(id, name, first, second);
    if (out)
        *(unsigned int*)out = value;
}
