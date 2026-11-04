#include "compat/ptr.h"
extern "C" char DAT_00414010[];
struct CollisionTargetPriorityCondition {
    int* vptr;
    int pad4;
    int pad8;
    int mC;
    int m10;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(int);
void* __cdecl Factory_vfunc5() {
    CollisionTargetPriorityCondition* p = (CollisionTargetPriorityCondition*)FUN_0008d690((int)sizeof(CollisionTargetPriorityCondition));
    if (p) {
        p->Init(0);
        p->vptr = (int*)((hulk_intptr)DAT_00414010);
        p->mC = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}