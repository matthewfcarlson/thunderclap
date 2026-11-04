#include "decls/data/game/hulkfight/motion.h"
// data: gCount_17a9a0 = DAT_004e1384

#include "compat/ptr.h"
#include "gen/fight.h"
extern "C" void __cdecl FUN_0016f880();
extern "C" void __cdecl FUN_0016f8a0();
extern "C" char DAT_0041872c[];
struct Param {
    char pad[0x18];
};

void* operator new(unsigned int n);
void Register(void* reg, Param** arr, int n);

struct Base_17a9a0 {
    int vt;
    char pad[0xc];
    int f10;
    int f14;
    Base_17a9a0(const char* name);
};

extern "C" void FUN_0017a9a0() {
    if ((*(int*)&DAT_004e1384) == 0) {
        Param* arr[2];
        Param* a = (Param*)operator new(sizeof(Param));
        if (a) {
            ((Param *)((fight::ParamValueFloat *)a)->FUN_00234960("timeBegin"));
            *(hulk_intptr*)a = ((hulk_intptr)DAT_0041872c);
            *(hulk_intptr*)((char*)a + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0016f880);
            arr[0] = a;
        } else {
            arr[0] = 0;
        }
        Param* b = (Param*)operator new(sizeof(Param));
        if (b) {
            ((Param *)((fight::ParamValueFloat *)b)->FUN_00234960("power"));
            *(hulk_intptr*)b = ((hulk_intptr)DAT_0041872c);
            *(hulk_intptr*)((char*)b + 0x10) = ((hulk_intptr)(void (__cdecl*)())&FUN_0016f8a0);
            arr[1] = b;
        } else {
            arr[1] = 0;
        }
        Register(((char*)&DAT_004e1380), arr, 2);
    }
    (*(int*)&DAT_004e1384)++;
}
