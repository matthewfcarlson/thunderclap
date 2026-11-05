#include "decls/data/platform/xbox/audio.h"
// data: mgr = DAT_004e76e8

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
struct Mgr_360ff0 {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl FUN_00360ff0() {
    __int64 a;
    __int64 b = FUN_002672f0("HalVoice", 0, 0);
    a = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Mgr_360ff0*)&DAT_004e76e8).FUN_002584d0(&a, &b, 0x88, 4);
    atexit(cleanup);
}