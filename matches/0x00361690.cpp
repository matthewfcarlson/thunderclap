#include "decls/data/engine/audio.h"
// data: gRegistry = DAT_004e7b98

typedef unsigned __int64 U64;
extern "C" U64 __cdecl Hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl Cleanup();
class Registry {
  public:
    void Register(U64*, U64*, int, int);
};
void FUN_00361690() {
    U64 a = Hash("HalRsdFileStream", 0, 0);
    U64 b = Hash("Runtime_Hal", 0, 0);
    (*(Registry*)&DAT_004e7b98).Register(&b, &a, 0x48, 4);
    atexit(Cleanup);
}