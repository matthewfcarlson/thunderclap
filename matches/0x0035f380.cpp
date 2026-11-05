#include "decls/data/engine/audio.h"
// data: Mixer = DAT_004290e4, Runtime_Mix = DAT_004290d8

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364160();
class Manager_35f380 {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
Manager_35f380 gManager_35f380;
void target() {
    __int64 a = FUN_002672f0(((char*)&DAT_004290e4), 0, 0);
    __int64 b = FUN_002672f0(((char*)&DAT_004290d8), 0, 0);
    gManager_35f380.FUN_002584d0(&b, &a, 48, 4);
    atexit(FUN_00364160);
}