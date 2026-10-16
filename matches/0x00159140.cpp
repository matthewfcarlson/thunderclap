#include "gen/fight.h"

extern "C" char DAT_00413fd0[];
extern "C" void* __cdecl Alloc(int);
struct Obj_159140 {
    int vf;
    int pad[4];
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_5() {
    Obj_159140* p = (Obj_159140*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_00413fd0);
        p->pad[2] = 0;
        p->pad[3] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
