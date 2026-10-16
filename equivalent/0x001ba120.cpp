// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CRenderManager,unsigned_int,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001ba120
#include "gen/global.h"

struct Vec_1ba120 {
    unsigned x, y, z;
};
struct Args_1ba120 {
    const char *name;
    Vec_1ba120 from;
    Vec_1ba120 to;
    unsigned radius;
};
class CRenderManager_1ba120 {
  public:
    unsigned Check(const char *name, Vec_1ba120 from, Vec_1ba120 to, unsigned radius);
};
typedef unsigned (CRenderManager_1ba120::*CheckFn_1ba120)(const char *, Vec_1ba120, Vec_1ba120, unsigned);
class Function_1ba120 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method4<CRenderManager, unsigned int, const char *,math::Vector,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CRenderManager_1ba120 * obj = (CRenderManager_1ba120 *)__p0; Args_1ba120 * args = (Args_1ba120 *)__p1; unsigned int * out = (unsigned int *)__p2;

    CheckFn_1ba120 fn = (*(CheckFn_1ba120 *)&this->f_1c);
    unsigned r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
