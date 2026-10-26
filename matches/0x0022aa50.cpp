#include "decls/data/engine/choreo2.h"
// data: gCount_22aa50 = DAT_004e5ac4

#include "compat/ptr.h"
extern "C" char DAT_00427534[];
struct LocomotionDriver {
    void* vf;
    char pad[0x1c];
    int a;
    int b;
    void InitA(LocomotionDriver*);
    void InitB(LocomotionDriver*);
    LocomotionDriver* Copy(LocomotionDriver*);
};
LocomotionDriver* LocomotionDriver::Copy(LocomotionDriver* src) {
    InitA(src);
    vf = (void*)((hulk_intptr)DAT_00427534);
    InitB(src);
    a = src->a;
    b = src->b;
    ++(*(int*)&DAT_004e5ac4);
    if ((*(int*)&DAT_004e5ac4) > (*(int*)&DAT_004e5ac8))
        (*(int*)&DAT_004e5ac8) = (*(int*)&DAT_004e5ac4);
    return this;
}