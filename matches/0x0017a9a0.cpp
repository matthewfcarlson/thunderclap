#include "compat/ptr.h"
extern "C" void __cdecl FUN_0016f880();
extern "C" void __cdecl FUN_0016f8a0();
extern "C" char DAT_0041872c[];
struct Param {
    char pad[0x18];
    Param* Init(const char* name);
};

void* operator new(unsigned int n);
void Register(void* reg, Param** arr, int n);
extern int gCount_17a9a0;
extern char gReg_17a9a0[];

struct Base_17a9a0 {
    int vt;
    char pad[0xc];
    int f10;
    int f14;
    Base_17a9a0(const char* name);
};

void FUN_0017a9a0() {
    if (gCount_17a9a0 == 0) {
        Param* arr[2];
        Param* a = (Param*)operator new(0x18);
        if (a) {
            a->Init("timeBegin");
            *(hulk_intptr*)a = ((hulk_intptr)DAT_0041872c);
            *(hulk_intptr*)((char*)a + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0016f880);
            arr[0] = a;
        } else {
            arr[0] = 0;
        }
        Param* b = (Param*)operator new(0x18);
        if (b) {
            b->Init("power");
            *(hulk_intptr*)b = ((hulk_intptr)DAT_0041872c);
            *(hulk_intptr*)((char*)b + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0016f8a0);
            arr[1] = b;
        } else {
            arr[1] = 0;
        }
        Register(gReg_17a9a0, arr, 2);
    }
    gCount_17a9a0++;
}
