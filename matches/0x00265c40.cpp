#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"
#include "decls/data/records.h"

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
extern "C" void __cdecl FUN_0026d7a0(void*);
// 0x0008d340 (_a) and 0x0008d330 (_b) are both `jmp` thunks to the heap's free 0x00267090, named by their target as in
// matches/0x000fa300.cpp (the thunks have no definition of their own in the tree).
extern "C" void __cdecl thunk_FUN_00267090_a(void*);
extern "C" void __cdecl thunk_FUN_00267090_b(void*);
extern "C" void __cdecl FUN_00265c40(void) {
    State_265c40* s = (*(State_265c40**)&DAT_00527c58);
    s->flag = 1;
    FUN_0026d7a0(&DAT_00527c28);
    hulk_intptr x = s->at30;
    s->at28 = x;
    s->at2c = x;
    if (x)
        thunk_FUN_00267090_a((void*)x);
    x = s->at1c;
    s->at14 = x;
    s->at18 = x;
    if (x)
        thunk_FUN_00267090_a((void*)x);
    thunk_FUN_00267090_b(s);
    (*(State_265c40**)&DAT_00527c58) = 0;
}
