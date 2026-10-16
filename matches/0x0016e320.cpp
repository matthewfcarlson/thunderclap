#include "gen/fight.h"

extern "C" char DAT_004169b8[];
struct Obj_16e320 {
    int vf;
    char pad[8];
    unsigned char flag;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::ThinkingCondition>::vfunc_5() {
    Obj_16e320* p = (Obj_16e320*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_004169b8);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)((Obj_16e320*)0);
}
