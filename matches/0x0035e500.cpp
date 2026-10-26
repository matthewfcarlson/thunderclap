#include "decls/data/game/hulkfight/motion.h"
// data: hulk_at_004e159c = DAT_004e159c

#include "compat/ptr.h"
extern "C" void __cdecl FUN_00363f90();
extern "C" int __cdecl _atexit(void (*)(void));
struct Reg {
    void Init(const char*, int);
};
void FUN_0035e500() {
    ((Reg*)((hulk_intptr)((char*)&DAT_004e159c)))->Init("sound/rsd", 0);
    _atexit(FUN_00363f90);
}
