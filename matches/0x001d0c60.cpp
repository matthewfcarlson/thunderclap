#include "decls/data/game/global.h"
// data: gError = DAT_0042251c, gTostring = DAT_00422548

extern int __cdecl FUN_00212d70(void*);
extern void __cdecl FUN_002135a0(void*, int, const char*);
extern void __cdecl FUN_00212ed0(void*, int);
extern void __cdecl FUN_002139a0(void*, int, int);
extern int __cdecl FUN_00213190(void*, int);
extern void __cdecl FUN_002133d0(void*, const char*);
extern void __cdecl FUN_00213c40(void*);
extern void __cdecl FUN_00212d80(void*, int);
int __cdecl target(void* state) {
    int count = FUN_00212d70(state);
    FUN_002135a0(state, -10001, DAT_00422548);
    int i = 1;
    if (count >= i) {
        do {
            FUN_00212ed0(state, -1);
            FUN_00212ed0(state, i);
            FUN_002139a0(state, 1, 1);
            int ok = FUN_00213190(state, -1);
            if (!ok) {
                FUN_002133d0(state, DAT_0042251c);
                FUN_00213c40(state);
            }
            FUN_00212d80(state, -2);
            ++i;
        } while (i <= count);
    }
    FUN_00212d80(state, -2);
    return 0;
}