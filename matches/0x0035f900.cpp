#include "decls/data/engine/audio.h"
// data: holder = DAT_004e6208

typedef __int64 I64;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Holder {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl FUN_0035f900() {
    HULK_SIZE32(AudioHalPositionalInfo, 0x64);
    I64 a = FUN_002672f0("HalPositionalInfo", 0, 0);
    I64 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Holder*)&DAT_004e6208).FUN_002584d0(&b, &a, (int)sizeof(AudioHalPositionalInfo), (int)__alignof(AudioHalPositionalInfo));
    atexit(cleanup);
}