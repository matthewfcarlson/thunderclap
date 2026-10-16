#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern int check(void*, int, void*, void*, int);
struct Obj_166c60 {
    void* getA();
    void* getB();
};

bool hulkfight::motion::TargetingCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * params = (void *)__p1; void * last = (void *)__p2;

    if (!check(params, 0, (void*)((int)DAT_00494b44), (void*)((int)DAT_00494b60), 0))
        return false;
    void* x = ((Obj_166c60*)params)->getA();
    void* y = ((Obj_166c60*)x)->getB();
    return *((unsigned char*)y + 0x32c) == this->f_0c;
}
