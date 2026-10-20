#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00414190[];
typedef unsigned int uint;
extern void* __cdecl Allocate(uint);
struct Obj_159930 {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
    int e;
    char flag;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDamageHealthCompareCondition>::vfunc_5() {
    Obj_159930* p = (Obj_159930*)Allocate(0x1c);
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00414190);
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
