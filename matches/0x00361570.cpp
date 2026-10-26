#include "decls/data/engine/audio.h"
// data: dataSequence = DAT_0042a620, mgr = DAT_004e7ac0, seqTrack = DAT_0042ab44

extern "C" __int64 __cdecl Make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Done();
struct Manager {
    void Init(__int64*, __int64*, int, int);
};
void FUN_00361570() {
    __int64 a = Make(DAT_0042ab44, 0, 0);
    __int64 b = Make(DAT_0042a620, 0, 0);
    (*(Manager*)&DAT_004e7ac0).Init(&b, &a, 0x48, 4);
    atexit(Done);
}