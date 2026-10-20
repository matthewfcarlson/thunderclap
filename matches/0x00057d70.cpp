#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f74e0[];
void* __cdecl Alloc(hulk_uintptr);
struct Obj_57d70 {
    void Init(int);
};
struct Tail_57d70 {
    void Init();
};
struct Raw_57d70 {
    hulk_uintptr vptr;
    char pad[8];
    int f;
    char pad2[12];
    unsigned char b;
};

template <> void* fight::ConditionFactoryTemplate<CFightNodePrevCondition>::vfunc_5() {
    Raw_57d70* p = (Raw_57d70*)Alloc(0x20);
    if (p != 0) {
        ((Obj_57d70*)p)->Init(0);
        p->vptr = ((hulk_intptr)DAT_003f74e0);
        p->f = 0;
        ((Tail_57d70*)((char*)p + 0x10))->Init();
        p->b = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
