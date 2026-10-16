// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CEffectManager,int,const_char_*,math::Vector,math::Vector>::vfunc_2 @ 0x001f77a0
#include "gen/global.h"

struct Vector_1f77a0 { float x, y, z; };
class CEffectManager_1f77a0 {
  public:
    int Dummy(const char* name, Vector_1f77a0 a, Vector_1f77a0 b);
};
struct Args_1f77a0 {
    const char* name;
    Vector_1f77a0 a;
    Vector_1f77a0 b;
};
class Function_1f77a0 {
  public:
    virtual void f0();
    virtual void f1();
};

template <> void Method3<CEffectManager, int, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f77a0 * obj = (CEffectManager_1f77a0 *)__p0; Args_1f77a0 * args = (Args_1f77a0 *)__p1; int * result = (int *)__p2;

    int r = (obj->*(*(int (CEffectManager_1f77a0::**)(const char *, Vector_1f77a0, Vector_1f77a0))&this->f_1c))(args->name, args->a, args->b);
    if (result)
        *result = r;
}
