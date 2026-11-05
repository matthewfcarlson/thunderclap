#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e7690

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl FUN_00360f80() {
    __int64 b = FUN_002672f0("SeqBuss", 0, 0);
    __int64 a = FUN_002672f0("Data_Sequence", 0, 0);
    (*(Registry*)&DAT_004e7690).FUN_002584d0(&a, &b, 0x14, 4);
    atexit(Cleanup);
}