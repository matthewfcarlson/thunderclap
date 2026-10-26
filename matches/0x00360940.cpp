#include "decls/data/engine/audio.h"
// data: g_cleanup = DAT_004e70e8

extern "C" void __cdecl FUN_00364530();
extern "C" int __cdecl _atexit(void (*)(void));
struct SeqEventVarPitchRandType_360940 {
    void Run();
};
void FUN_00360940() {
    (*(SeqEventVarPitchRandType_360940*)&DAT_004e70e8).Run();
    _atexit(FUN_00364530);
}
