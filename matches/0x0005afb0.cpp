// Same code shape as 0x0005adb0 (propagated; names are from that function)
#include "gen/global.h"

struct Obj_5afb0 {
    char pad[0x330];
    int* p330;
    int* p334;
};
struct Context_5afb0 {
    Obj_5afb0* first();
    Obj_5afb0* second();
};

void* CGrappleSequenceTrack::vfunc_8(void* __p0, void* __p1) { void * p = (void *)__p1;

    if (!p)
        return (void*)(0);
    Obj_5afb0* a = ((Context_5afb0*)p)->first();
    if (!a)
        return (void*)(0);
    Obj_5afb0* b = ((Context_5afb0*)a)->second();
    if (!b)
        return (void*)(0);
    if (b->p334)
        return (void*)((int*)((char*)b->p334 + 0xdc));
    if (b->p330)
        return (void*)((int*)((char*)b->p330 + 0xdc));
    return (void*)(0);
}
