#include "decls/data/engine/audio.h"
// data: registry = DAT_004e6e90

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void FUN_00360670() {
    unsigned __int64 a = FUN_002672f0("SeqActionVarVolume", 0, 0);
    unsigned __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6e90).FUN_002584d0((__int64*)&b, (__int64*)&a, 16, 4);
    atexit(cleanup);
}