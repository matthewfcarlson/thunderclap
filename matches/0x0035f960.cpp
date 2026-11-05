#include "decls/data/engine/audio.h"
// data: registry = DAT_004e6250

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364290();
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
void __cdecl FUN_0035f960() {
    U64 a = FUN_002672f0("HalListener", 0, 0);
    U64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Registry*)((char*)&DAT_004e6208 + 72)).FUN_002584d0(&b, &a, 64, 4);
    atexit(FUN_00364290);
}