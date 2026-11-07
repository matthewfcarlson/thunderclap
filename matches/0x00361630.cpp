#include "decls/data/engine/audio.h"
// data: gRegistry_361630 = DAT_004e7b50

typedef unsigned __int64 U64_361630;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl FUN_00364740();
class Registry_361630 {
  public:
    void FUN_002584d0(U64_361630*, U64_361630*, int, int);
};
void __cdecl FUN_00361630() {
    U64_361630 a = FUN_002672f0("HalRsdFileHeader", 0, 0);
    U64_361630 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Registry_361630*)((char*)&DAT_004e7b50)).FUN_002584d0(&b, &a, 0x1a4, 4);
    atexit(FUN_00364740);
}