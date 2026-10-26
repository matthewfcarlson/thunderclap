#include "decls/data/engine/audio.h"
// data: gManager = DAT_004e7928

extern "C" __int64 __cdecl Fetch(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl Cleanup();
struct Manager {
    void Init(const __int64*, const __int64*, int, int);
};
void __cdecl Target() {
    __int64 a = Fetch("CircBuf", 0, 0);
    __int64 b = Fetch("Runtime_Hal", 0, 0);
    (*(Manager*)((char*)&DAT_004e78e0 + 72)).Init(&b, &a, 0x30, 4);
    atexit(Cleanup);
}