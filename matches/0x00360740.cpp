#include "decls/data/engine/audio.h"
// data: registry = DAT_004e6f40

extern "C" __int64 FUN_002672f0(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
extern "C" void FUN_003644e0();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void init() {
    HULK_SIZE32(AudioSeqActionVarTempo, 0x10);
    __int64 a = FUN_002672f0("SeqActionVarTempo", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)((char*)&DAT_004e6f40)).FUN_002584d0(&b, &a, (int)sizeof(AudioSeqActionVarTempo), (int)__alignof(AudioSeqActionVarTempo));
    atexit(FUN_003644e0);
}