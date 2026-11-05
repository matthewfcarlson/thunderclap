#include "decls/data/engine/audio.h"
// data: gManager = DAT_004e7898

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003646b0();
class Manager {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl Target() {
    __int64 a = FUN_002672f0("HalBuffer", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager*)&DAT_004e7898).FUN_002584d0(&b, &a, 0x28, 4);
    atexit(FUN_003646b0);
}