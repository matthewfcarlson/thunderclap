#include "decls/data/engine/audio.h"
// data: gHelper_360a80 = DAT_004e7200

struct SeqEventStreamType_360a80 {
    void FUN_002540a0();
};
extern "C" int __cdecl _atexit(void (*)());
extern "C" void __cdecl FUN_00364570();
void __cdecl FUN_00360a80() {
    (*(SeqEventStreamType_360a80*)&DAT_004e7200).FUN_002540a0();
    _atexit((void (*)())FUN_00364570);
}
