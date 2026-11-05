#include "decls/data/engine/audio.h"

extern "C" int __cdecl atexit(void (*)(void));
extern "C" void __cdecl FUN_00364550();
struct SeqEventVarPitchType_360a10 {
    void FUN_002538a0();
};
void __cdecl FUN_00360a10() {
    (*(SeqEventVarPitchType_360a10*)&DAT_004e7198).FUN_002538a0();
    atexit((void (*)(void))FUN_00364550);
}
