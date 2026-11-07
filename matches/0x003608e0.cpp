#include "decls/data/records.h"
typedef unsigned __int64 U64;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
struct Registry {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern Registry registry;
void __cdecl FUN_003608e0() {
    HULK_SIZE32(AudioSeqActionVarPitchRand, 0x10);
    U64 a = FUN_002672f0("SeqActionVarPitchRand", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    registry.FUN_002584d0((__int64*)&b, (__int64*)&a, (int)sizeof(AudioSeqActionVarPitchRand), (int)__alignof(AudioSeqActionVarPitchRand));
    atexit(cleanup);
}