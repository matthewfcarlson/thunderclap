#include "decls/data/game/global.h"
// data: gGlobal_35cb10 = DAT_004dcf00

extern "C" int __cdecl _atexit(void (*)());
struct Global {
    void FUN_0027af00();
};
void FUN_00363c30();
void FUN_0035cb10() {
    (*(Global*)&DAT_004dcf00).FUN_0027af00();
    _atexit(FUN_00363c30);
}
