#include "gen/global.h"

extern "C" void _ReadWriteBarrier();
struct CSPManager_1e2420 {};
struct Arguments {
    int a;
    int b;
    const char* c;
};

template <> void Closure3<CSPManager, void, int, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; void * unused2 = (void *)__p2;

    int a = args->a;
    _ReadWriteBarrier();
    int b = args->b;
    const char* c = args->c;
    ((*(CSPManager_1e2420 * *)&this->f_20)->*(*(void (CSPManager_1e2420::**)(int, int, const char *))&this->f_1c))(a, b, c);
    _ReadWriteBarrier();
}
