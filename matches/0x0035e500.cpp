#include "compat/ptr.h"
extern "C" char hulk_at_004e159c[];
extern "C" void __cdecl FUN_00363f90();
extern "C" int __cdecl _atexit(void (*)(void));
struct Reg {
    void Init(const char*, int);
};
void FUN_0035e500() {
    ((Reg*)((hulk_intptr)hulk_at_004e159c))->Init("sound/rsd", 0);
    _atexit(FUN_00363f90);
}
