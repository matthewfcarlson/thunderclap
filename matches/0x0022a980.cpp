#include "decls/data/engine/choreo2.h"
// data: gCount_22a980 = DAT_004e5ac4, gHigh_22a980 = DAT_004e5ac8

#include "compat/ptr.h"
extern "C" char DAT_00427534[];
struct PartitionDriver_22a980 {
    void Init(int);
};
struct LocomotionDriver : PartitionDriver_22a980 {
    hulk_intptr vptr;
    char pad[0x1b];
    int a;
    int b;
    LocomotionDriver* Init(int);
};
LocomotionDriver* LocomotionDriver::Init(int x) {
    PartitionDriver_22a980::Init(x);
    a = 0;
    b = 0;
    vptr = ((hulk_intptr)DAT_00427534);
    int n = ++(*(int*)&DAT_004e5ac4);
    if (n > (*(int*)&DAT_004e5ac8))
        (*(int*)&DAT_004e5ac8) = n;
    return this;
}