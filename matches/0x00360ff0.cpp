#include "decls/data/platform/xbox/audio.h"
// data: mgr = DAT_004e76e8

extern "C" __int64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
struct Mgr_360ff0 {
    void init(__int64*, __int64*, int, int);
};
void __cdecl FUN_00360ff0() {
    __int64 a;
    __int64 b = lookup("HalVoice", 0, 0);
    a = lookup("Runtime_Hal", 0, 0);
    (*(Mgr_360ff0*)&DAT_004e76e8).init(&a, &b, 0x88, 4);
    atexit(cleanup);
}