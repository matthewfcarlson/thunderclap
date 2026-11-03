#include "decls/data/game/hulkfight/ai.h"
// data: counter = DAT_004e0ccc, registry_1214f0 = DAT_004e0cc8

#include "compat/ptr.h"
#include "gen/fight.h"
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
};
extern "C" void __cdecl FUN_002347b0(void*, Param**, int);
void target() {
    if ((*(int*)&DAT_004e0ccc) == 0) {
        Param* list[7];
        Param* p;
        p = (Param*)alloc(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeBegin");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd30);
            list[0] = p;
        } else
            list[0] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeEnd");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd40);
            list[1] = p;
        } else
            list[1] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("distance");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd50);
            list[2] = p;
        } else
            list[2] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("turnRate");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd60);
            list[3] = p;
        } else
            list[3] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("heightMin");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd90);
            list[4] = p;
        } else
            list[4] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("heightMax");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bdb0);
            list[5] = p;
        } else
            list[5] = 0;
        p = (Param*)alloc(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("speed");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bdd0);
            list[6] = p;
        } else
            list[6] = 0;
        FUN_002347b0(((void**)&DAT_004e0cc8), list, 7);
    }
    ++(*(int*)&DAT_004e0ccc);
}
