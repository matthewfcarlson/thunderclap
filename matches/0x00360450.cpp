#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e6ce0

typedef __int64 I64;
extern "C" I64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364470();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl FUN_00360450() {
    HULK_SIZE32(AudioSeqActionChannelVolumes, 0x10);
    I64 a = FUN_002672f0("SeqActionChannelVolumes", 0, 0);
    I64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6ce0).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionChannelVolumes), (int)__alignof(AudioSeqActionChannelVolumes));
    atexit(FUN_00364470);
}