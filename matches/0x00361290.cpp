#include "decls/data/engine/audio.h"
// data: gHolder = DAT_004e78e0

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003646c0();
class Holder {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void target() {
    HULK_SIZE32(AudioSeqTrackPlayer, 0x60);
    __int64 a = FUN_002672f0("SeqTrackPlayer", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Holder*)&DAT_004e78e0).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqTrackPlayer), (int)__alignof(AudioSeqTrackPlayer));
    atexit(FUN_003646c0);
}
