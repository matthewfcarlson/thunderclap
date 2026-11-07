#include "decls/data/engine/audio.h"
// data: beat = DAT_0042ab20, global = DAT_004e7a30, sequence = DAT_0042a620

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
class Object {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364700();
void __cdecl target() {
    __int64 a = FUN_002672f0(DAT_0042ab20, 0, 0);
    __int64 b = FUN_002672f0(DAT_0042a620, 0, 0);
    (*(Object*)&DAT_004e7a30).FUN_002584d0(&b, &a, 8, 4);
    atexit(FUN_00364700);
}