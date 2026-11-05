#include "decls/data/platform/xbox/audio.h"
// data: global_361050 = DAT_004e7730

struct Pair_361050 {
    int a, b;
};
extern "C" Pair_361050 __cdecl FUN_002672f0(const char*, int, int);
struct Obj_361050 {
    void FUN_002584d0(Pair_361050*, Pair_361050*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364660();
void __cdecl FUN_00361050() {
    Pair_361050 a = FUN_002672f0("HalVoiceChannel", 0, 0);
    Pair_361050 b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Obj_361050*)((char*)&DAT_004e76e8 + 72)).FUN_002584d0(&b, &a, 128, 4);
    atexit(FUN_00364660);
}