// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015bc90 @ 0x0015bc90
#include "compat/ptr.h"
extern "C" char DAT_00415a40[];
struct Vec2_15bc90 {
    int a, b;
    void FUN_0027af00();
};
struct Base_15bc90 {
    void FUN_00236d40();
};
struct HeliLocomotionTrack : Base_15bc90 {
    void *vptr_unused;
    char pad4[0x0c - 4];
    int f0c;
    float f10;
    float f14, f18;
    int f1c, f20, f24, f28;
    float f2c, f30, f34, f38, f3c;
    int f40;
    float f44;
    int f48, f4c, f50;
    float f54, f58, f5c, f60, f64;
    int f68;
    float f6c;
    int f70, f74, f78, f7c, f80, f84, f88, f8c;
    float f90, f94;
    int f98;
    char pad9c[4];
    Vec2_15bc90 fa0;
    float fa8;
    int fac, fb0, fb4;
    float fb8, fbc, fc0, fc4, fc8, fcc, fd0, fd4;
    HeliLocomotionTrack *ctor();
};
HeliLocomotionTrack *HeliLocomotionTrack::ctor() {
    FUN_00236d40();
    *(volatile hulk_ulongptr *)this = (hulk_ulongptr)DAT_00415a40;
    f0c = 0;
    f14 = 100.0f;
    f18 = 25.0f;
    f1c = 0; f20 = 0; f24 = 0; f28 = 0;
    f2c = -0.5235988f;
    f30 = 0.5235988f;
    f10 = -1.0f;
    f34 = 1.0f;
    f38 = 3.0f;
    f3c = 1.5f;
    f40 = 0;
    f44 = -1.0f;
    f48 = 0;
    f5c = 1.0f;
    f64 = 1.5f;
    f4c = 0; f50 = 0;
    f54 = -0.5235988f;
    f58 = 0.5235988f;
    f60 = 3.0f;
    f68 = 0;
    f6c = -1.0f;
    f70 = 0; f74 = 0; f78 = 0; f7c = 0; f80 = 0; f84 = 0; f88 = 0; f8c = 0;
    f90 = 0.1f; f94 = 0.1f;
    f98 = 0;
    fa0.FUN_0027af00();
    fa8 = 10.0f;
    fac = 0; fb0 = 0; fb4 = 0;
    fb8 = 10.0f; fbc = 10.0f;
    fc0 = 40.0f; fc4 = 5.0f; fc8 = 0.01f;
    fcc = 0.1f; fd0 = 0.1f; fd4 = 0.1f;
    return this;
}
