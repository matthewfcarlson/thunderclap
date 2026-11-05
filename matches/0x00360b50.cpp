#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e72b0

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Finish();
class Registry {
  public:
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
void __cdecl Target() {
    __int64 a = FUN_002672f0("SeqActionSilence", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e72b0).FUN_002584d0(&b, &a, 0x1c, 4);
    atexit(Finish);
}
