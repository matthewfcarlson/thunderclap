#include "decls/data/engine/audio.h"
// data: gManager_35f580 = DAT_004e5fa8

extern "C" __int64 FUN_002672f0(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003641e0();
struct Manager_35f580 {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl target() {
    __int64 a = FUN_002672f0("SeqPlayer", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Manager_35f580*)&DAT_004e5fa8).FUN_002584d0(&b, &a, 0xb8, 4);
    atexit(FUN_003641e0);
}
