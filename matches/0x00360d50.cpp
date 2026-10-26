#include "decls/data/engine/audio.h"

extern "C" void __cdecl _atexit(void (*)());
struct SeqEventLogicOrType_360d50 {
    void Init();
};
extern void Cleanup();
void __cdecl FUN_00360d50() {
    (*(SeqEventLogicOrType_360d50*)((char*)&DAT_004e7410 + 72)).Init();
    _atexit(Cleanup);
}
