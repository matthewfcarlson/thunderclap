#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e7b98

typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl Cleanup();
class Registry {
  public:
    void FUN_002584d0(U64*, U64*, int, int);
};
void FUN_00361690() {
    U64 a = FUN_002672f0("HalRsdFileStream", 0, 0);
    U64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Registry*)&DAT_004e7b98).FUN_002584d0(&b, &a, 0x48, 4);
    atexit(Cleanup);
}