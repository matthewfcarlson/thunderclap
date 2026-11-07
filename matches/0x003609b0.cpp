#include "decls/data/engine/audio.h"
// data: registry = DAT_004e7150

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364540();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
struct Pair {
    __int64 a, b;
};
void __cdecl FUN_003609b0() {
    Pair p;
    p.a = FUN_002672f0("SeqActionVarPitch", 0, 0);
    p.b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)((char*)&DAT_004e7150)).FUN_002584d0(&p.b, &p.a, 16, 4);
    atexit(FUN_00364540);
}