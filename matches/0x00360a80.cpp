#include "decls/data/engine/audio.h"
// data: gHelper_360a80 = DAT_004e7200

struct SeqEventStreamType_360a80 {
    void Run();
};
extern "C" int __cdecl _atexit(void (*)());
extern void __cdecl FUN_00364570();
void __cdecl FUN_00360a80() {
    (*(SeqEventStreamType_360a80*)&DAT_004e7200).Run();
    _atexit((void (*)())FUN_00364570);
}
