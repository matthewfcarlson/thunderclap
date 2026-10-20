#include "compat/ptr.h"
#include "gen/global.h"

extern void* FUN_0008d690(hulk_uintptr);
struct Obj_605f0 {
    char pad[0x104];
    int value;
};
extern Obj_605f0* FUN_0005a430(int);
struct Alloc_605f0 {
    int invoke(CGrappleMotionTrailTrack*, int);
};

int CGrappleMotionTrailTrack::vfunc_12(int arg) {
    CGrappleMotionTrailTrack* self = this;
    Alloc_605f0* p = (Alloc_605f0*)FUN_0008d690(0x28);
    if (p) {
        int v = FUN_0005a430(arg)->value;
        return p->invoke(self, v);
    }
    return 0;
}
