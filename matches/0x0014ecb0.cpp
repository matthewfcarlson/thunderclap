#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
int FUN_00344e74(void*, int, const void*, const void*, int);
struct V {
    virtual char a();
    virtual char b();
    virtual char c();
    virtual unsigned char* d();
};

bool hulkfight::motion::CollisionExplosionCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * param = (void *)__p1; void * extra = (void *)__p2;

    int r = FUN_00344e74(param, 0, (const void*)((int)DAT_00494b44), (const void*)((int)DAT_00494b60), 0);
    if (r == 0)
        return (bool)(0);
    unsigned char* x = ((V*)param)->d();
    if (x == 0)
        return (bool)(0);
    return (bool)(this->f_0c == x[0x90] ? 1 : 0);
}
