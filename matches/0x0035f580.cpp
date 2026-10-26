#include "decls/data/engine/audio.h"
// data: gManager_35f580 = DAT_004e5fa8

extern "C" __int64 lookup(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
void __cdecl cleanup();
struct Manager_35f580 {
    void registerTypes(__int64*, __int64*, int, int);
};
void __cdecl target() {
    __int64 a = lookup("SeqPlayer", 0, 0);
    __int64 b = lookup("Runtime_Sequence", 0, 0);
    (*(Manager_35f580*)&DAT_004e5fa8).registerTypes(&b, &a, 0xb8, 4);
    atexit(cleanup);
}
