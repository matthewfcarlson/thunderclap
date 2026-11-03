#include "gen/global.h"
#include "gen/owners.h"

struct Obj_5adb0 {
    char pad[0x330];
    int* p330;
    int* p334;
};
struct Context_5adb0 {
    Obj_5adb0* second();
};

void* CGrappleOpportunityTrack::vfunc_8(void* __p0, void* __p1) { void * p = (void *)__p1;

    if (!p)
        return (void*)(0);
    Obj_5adb0* a = ((Obj_5adb0 *)((owners::Object_592a0 *)(((Context_5adb0*)p)))->FUN_000592a0());
    if (!a)
        return (void*)(0);
    Obj_5adb0* b = ((Context_5adb0*)a)->second();
    if (!b)
        return (void*)(0);
    if (b->p334)
        return (void*)((int*)((char*)b->p334 + 0xdc));
    if (b->p330)
        return (void*)((int*)((char*)b->p330 + 0xdc));
    return (void*)(0);
}
