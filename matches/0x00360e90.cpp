#include "decls/data/engine/audio.h"
// data: global = DAT_004e7570

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Global {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void __cdecl FUN_00360e90() {
    __int64 a = FUN_002672f0("SeqActionClip", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Global*)((char*)&DAT_004e7570)).FUN_002584d0(&b, &a, 0x1c, 4);
    atexit(cleanup);
}