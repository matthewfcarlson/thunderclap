#include "decls/data/engine/audio.h"

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
class Table {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364760();
void __cdecl target() {
    __int64 a;
    __int64 b = FUN_002672f0("PointerUid", 0, 0);
    a = FUN_002672f0("Om", 0, 0);
    (*(Table*)&DAT_004e7be0).FUN_002584d0(&a, &b, 32, 8);
    atexit(FUN_00364760);
}