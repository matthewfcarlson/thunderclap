#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e7410

typedef unsigned __int64 U64;
extern U64 __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003645c0();
void __cdecl Init() {
    U64 first = FUN_002672f0("SeqCommandLogicOr", 0, 0);
    U64 second = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e7410).FUN_002584d0(&second, &first, 12, 4);
    atexit(FUN_003645c0);
}