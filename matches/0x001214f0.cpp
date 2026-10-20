#include "compat/ptr.h"
extern "C" void __cdecl FUN_0011bd30();
extern "C" void __cdecl FUN_0011bd40();
extern "C" void __cdecl FUN_0011bd50();
extern "C" void __cdecl FUN_0011bd60();
extern "C" void __cdecl FUN_0011bd90();
extern "C" void __cdecl FUN_0011bdb0();
extern "C" void __cdecl FUN_0011bdd0();
extern "C" char DAT_0040f848[];
void* __cdecl alloc(hulk_uintptr);
struct Param {
    hulk_intptr vft;
    int pad[3];
    hulk_intptr value;
    void Init(const char*);
};
void __cdecl register_params(void*, Param**, int);
extern int counter;
extern void* registry_1214f0;
void target() {
    if (counter == 0) {
        Param* list[7];
        Param* p;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("timeBegin");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd30);
            list[0] = p;
        } else
            list[0] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("timeEnd");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd40);
            list[1] = p;
        } else
            list[1] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("distance");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd50);
            list[2] = p;
        } else
            list[2] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("turnRate");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd60);
            list[3] = p;
        } else
            list[3] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("heightMin");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd90);
            list[4] = p;
        } else
            list[4] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("heightMax");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bdb0);
            list[5] = p;
        } else
            list[5] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            p->Init("speed");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bdd0);
            list[6] = p;
        } else
            list[6] = 0;
        register_params(&registry_1214f0, list, 7);
    }
    ++counter;
}
