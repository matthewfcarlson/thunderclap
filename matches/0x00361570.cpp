#include "decls/data/engine/audio.h"
// data: dataSequence = DAT_0042a620, mgr = DAT_004e7ac0, seqTrack = DAT_0042ab44

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Done();
struct Manager {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void FUN_00361570() {
    HULK_SIZE32(AudioSeqTrack, 0x48);
    __int64 a = FUN_002672f0(DAT_0042ab44, 0, 0);
    __int64 b = FUN_002672f0(DAT_0042a620, 0, 0);
    (*(Manager*)&DAT_004e7ac0).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqTrack), (int)__alignof(AudioSeqTrack));
    atexit(Done);
}