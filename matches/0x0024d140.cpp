#include "compat/ptr.h"
struct Obj_24d140 {
    char pad[0x54];
    float value;
    float slot58;
    float slot5c;
    float slot60;
};
float __cdecl f1(int, Obj_24d140*);
float __cdecl f2(int, Obj_24d140*);
float __cdecl f3(int, Obj_24d140*);
float __cdecl f4(int, Obj_24d140*);
extern "C" void __cdecl FUN_0024cf20(void *, const void *, float *, float *);
extern "C" void __cdecl FUN_0024d140(int a, Obj_24d140* b) {
    // MSVC evaluates the operands right to left: f1, then f2, then f3
    float x1 = f1(a, b);
    float x2 = f2(a, b) * x1;
    b->value = f3(a, b) * x2;
    b->slot60 = f4(a, b);
    FUN_0024cf20((void *)(hulk_uintptr)(int)a, (Obj_24d140 *)b, &b->slot58, &b->slot5c);
}