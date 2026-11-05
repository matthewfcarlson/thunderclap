#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
// data: logname = DAT_00400844, lua = DAT_003f8d4c, visual = DAT_00400848

extern "C" int __cdecl FUN_00096600(int, const char*);
extern "C" void __stdcall FUN_0008da80(hulk_intptr a, hulk_intptr b) {
    if (FUN_00096600(b, DAT_00400848) != 0) {
        if (FUN_00096600(b, DAT_00400844) != 0) {
            FUN_00096600(b, DAT_003f8d4c);
        }
    }
}