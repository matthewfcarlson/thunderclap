// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Function2<void,int,math::Vector>::vfunc_2 @ 0x001b37e0
#include "compat/ptr.h"
#include "gen/global.h"

namespace math { struct Vector_1b37e0 { float x,y,z; }; }
struct Function_1b37e0 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Function2<void, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; const math::Vector_1b37e0 * value = (const math::Vector_1b37e0 *)__p1; hulk_intptr extra = (hulk_intptr)__p2;

    (*(void (**)(int, math::Vector_1b37e0))&this->f_1c)(*(const int*)value, *(const math::Vector_1b37e0*)((const char*)value+4));
}
