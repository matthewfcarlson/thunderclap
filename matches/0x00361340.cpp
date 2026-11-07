#include "decls/data/engine/audio.h"
// data: gManager = DAT_004e7928

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_003646d0();
struct Manager {
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
void __cdecl Target() {
    HULK_SIZE32(AudioCircBuf, 0x30);
    __int64 a = FUN_002672f0("CircBuf", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager*)((char*)&DAT_004e7928)).FUN_002584d0(&b, &a, (int)sizeof(AudioCircBuf), (int)__alignof(AudioCircBuf));
    atexit(FUN_003646d0);
}