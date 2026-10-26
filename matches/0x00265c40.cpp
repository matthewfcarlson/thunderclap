#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"

#include "compat/ptr.h"
struct State_265c40 {
    unsigned char p0[1];
    unsigned char flag;
    unsigned char p2[0x12];
    hulk_intptr at14;
    hulk_intptr at18;
    int at1c;
    unsigned char p20[4];
    int at24;
    hulk_intptr at28;
    hulk_intptr at2c;
    int at30;
};
void __cdecl FUN_0026d7a0(void*);
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
void __cdecl FUN_00265c40(void) {
    State_265c40* s = (*(State_265c40**)&DAT_00527c58);
    s->flag = 1;
    FUN_0026d7a0((void*)&(*(char*)((char*)&DAT_0051de40 + 40424)));
    hulk_intptr x = s->at30;
    s->at28 = x;
    s->at2c = x;
    if (x)
        FUN_0008d340((void*)x);
    x = s->at1c;
    s->at14 = x;
    s->at18 = x;
    if (x)
        FUN_0008d340((void*)x);
    FUN_0008d330(s);
    (*(State_265c40**)&DAT_00527c58) = 0;
}
