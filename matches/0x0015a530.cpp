#include "gen/fight.h"

extern "C" void* __cdecl alloc(unsigned int);
extern "C" int CollisionThrownObjectCondition_vftable;

struct Helper_15a530 {
    char pad[8];
    void Go();
};
struct Cond_15a530 {
    void* vp;
    char pad1[8];
    char flag;
    char pad2[3];
    Helper_15a530 h;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrownObjectCondition>::vfunc_5() {
    Cond_15a530* p = (Cond_15a530*)alloc(0x18);
    if (p) {
        p->Init(0);
        p->vp = (void*)&CollisionThrownObjectCondition_vftable;
        p->flag = 1;
        p->h.Go();
        return (void*)(p);
    }
    return (void*)(0);
}
