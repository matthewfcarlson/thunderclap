// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Function2<void,int,math::Vector>::vfunc_2 @ 0x001b37e0
#include "gen/global.h"

namespace math { struct Vector_1b37e0 { float x,y,z; }; }
struct Function_1b37e0 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Function2<void, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; const math::Vector_1b37e0 * value = (const math::Vector_1b37e0 *)__p1; int extra = (int)__p2;

    (*(void (**)(int, math::Vector_1b37e0))&this->f_1c)(*(const int*)value, *(const math::Vector_1b37e0*)((const char*)value+4));
}
