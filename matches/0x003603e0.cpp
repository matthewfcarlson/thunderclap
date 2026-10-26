#include "decls/data/engine/audio.h"
// data: gGlobal_3603e0 = DAT_004e6c78

extern "C" void __cdecl FUN_00364460();
extern "C" int __cdecl _atexit(void (*)());
struct SeqEventPlayTrackType_3603e0 {
    void Init();
};
void __cdecl FUN_003603e0() {
    (*(SeqEventPlayTrackType_3603e0*)((char*)&DAT_004e6bc8 + 176)).Init();
    _atexit(FUN_00364460);
}
