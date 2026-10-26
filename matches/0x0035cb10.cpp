#include "decls/data/game/global.h"
// data: gGlobal_35cb10 = DAT_004dcf00

extern "C" int __cdecl _atexit(void (*)());
struct Global {
    void Init();
};
void Cleanup();
void FUN_0035cb10() {
    (*(Global*)&DAT_004dcf00).Init();
    _atexit(Cleanup);
}
