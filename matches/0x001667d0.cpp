#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
extern int __cdecl castcheck(void*, int, void*, void*, int);

struct Lvl3 {
    unsigned char third();
};
struct Lvl2 {
    Lvl3* second();
};
struct Lvl1 {
    Lvl2* first();
};

bool hulkfight::motion::ThinkingCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * p = (void *)__p1; void * c = (void *)__p2;

    if (!castcheck(p, 0, (void*)((hulk_intptr)DAT_00494b44), (void*)((hulk_intptr)DAT_00494b60), 0))
        return false;
    Lvl1* q = (Lvl1*)p;
    Lvl2* r = q->first();
    Lvl3* s = r->second();
    unsigned char v = this->f_0c;
    return s->third() == v;
}
