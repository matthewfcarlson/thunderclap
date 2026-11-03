// STATUS: equivalent (tools/equiv.py level 3: 7848 inputs, branch coverage 14/14)
// FUN_000b5250 @ 0x000b5250
// cl-flags: /GS
#include "gen/owners.h"

struct Locale {
};

struct TextEntry_b5250 {
};

Locale *__cdecl FUN_000fc1b0();
void __cdecl FUN_000fc020(char *buf, int size, const char *fmt, ...);
extern "C" void __cdecl FUN_000fc000(char *buf, int size, const char *fmt, ...);

void __stdcall FUN_000b5250(TextEntry_b5250 *entry, const char *key, const char *k2, const char *k3,
                            const char *k4, const char *k5, const char *k6, const char *k7)
{
    char buf[0x100];
    Locale *L;
    int id;
    const char *a2;
    const char *a3;
    const char *a4;
    const char *a5;
    const char *a6;
    const char *a7;

    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)key));
    const char *text = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    a2 = k2;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k2));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k2));
        a2 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a3 = k3;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k3));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k3));
        a3 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a4 = k4;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k4));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k4));
        a4 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a5 = k5;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k5));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k5));
        a5 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a6 = k6;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k6));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k6));
        a6 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }
    a7 = k7;
    L = FUN_000fc1b0();
    id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k7));
    if (((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id)) != 0) {
        L = FUN_000fc1b0();
        id = ((int)((owners::A_f7d30 *)L)->FUN_000f7d30((hulk_intptr)k7));
        a7 = ((const char *)((owners::C_f7220 *)L)->FUN_000f7220((hulk_intptr)id));
    }

    if (text != 0)
        FUN_000fc020(buf, 0x100, text, a2, a3, a4, a5, a6, a7);
    else
        FUN_000fc000(buf, 0x100, key, a2, a3, a4, a5, a6, a7);
    ((owners::Obj_f79a0 *)entry)->FUN_000f79a0((const short *)buf, (hulk_intptr)0);
}
