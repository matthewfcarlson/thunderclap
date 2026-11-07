#include "decls/data/engine/audio.h"
// data: g_mgr_3604d0 = DAT_004e6d30

extern "C" void __cdecl FUN_00364490();
extern "C" int __cdecl atexit(void (*)());
struct SeqEventChannelVolumesType_3604d0 {
    void FUN_00251b40();
};
void Register() {
    (*(SeqEventChannelVolumesType_3604d0*)((char*)&DAT_004e6d30)).FUN_00251b40();
    atexit(FUN_00364490);
}
