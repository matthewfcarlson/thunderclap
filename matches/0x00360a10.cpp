#include "decls/data/engine/audio.h"

extern "C" int __cdecl atexit(void (*)(void));
extern void __cdecl FUN_00364550();
struct SeqEventVarPitchType_360a10 {
    void Init();
};
void __cdecl FUN_00360a10() {
    (*(SeqEventVarPitchType_360a10*)&DAT_004e7198).Init();
    atexit((void (*)(void))FUN_00364550);
}
