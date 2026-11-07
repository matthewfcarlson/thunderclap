#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e7360

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003645a0();
struct Registry {
    void FUN_002584d0(U64*, U64*, int, int);
};
void Init() {
    HULK_SIZE32(AudioSeqCommandLogicRepeat, 0x18);
    U64 a = FUN_002672f0("SeqCommandLogicRepeat", 0, 0);
    U64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)((char*)&DAT_004e7360)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqCommandLogicRepeat), (int)__alignof(AudioSeqCommandLogicRepeat));
    atexit(FUN_003645a0);
}