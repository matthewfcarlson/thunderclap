#include "decls/data/game/unknown.h"
// data: logname = DAT_00400844, lua = DAT_003f8d4c, visual = DAT_00400848

extern int __cdecl Find(int, const char*);
extern "C" void __stdcall FUN_0008da80(int a, int b) {
    if (Find(b, DAT_00400848) != 0) {
        if (Find(b, DAT_00400844) != 0) {
            Find(b, DAT_003f8d4c);
        }
    }
}