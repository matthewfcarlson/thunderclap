// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_2 @ 0x001ba7a0
#include "gen/global.h"

struct CRenderManager_1ba7a0 {
    unsigned int FUN_001ba7a0(unsigned int, const char *, float, float);
};
struct Arguments {
    unsigned int id;
    const char *name;
    float first;
    float second;
};

template <> void Closure4<CRenderManager, unsigned int, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * args = (Arguments *)__p1; unsigned int * result = (unsigned int *)__p2;

    unsigned int value = ((*(CRenderManager_1ba7a0 * *)&this->f_20)->*(*(unsigned int (CRenderManager_1ba7a0::**)(unsigned int, const char *, float, float))&this->f_1c))(args->id, args->name, args->first, args->second);
    if (result) *result = value;
}
