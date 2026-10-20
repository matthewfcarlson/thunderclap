#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern int Cast(void*, int, void*, void*, int);
struct Obj_14ec10 {
    Obj_14ec10* A();
    Obj_14ec10* B();
    unsigned char C();
};

bool hulkfight::motion::HitPushbackCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * params = (void *)__p1; void * c = (void *)__p2;

    if (!Cast(params, 0, (void*)((hulk_intptr)DAT_00494b44), (void*)((hulk_intptr)DAT_00494b60), 0))
        return false;
    Obj_14ec10* x = ((Obj_14ec10*)params)->A();
    Obj_14ec10* y = x->B();
    unsigned char z = y->C();
    return (unsigned char)(z - this->f_0c) == 0;
}
