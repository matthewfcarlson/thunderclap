#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_001e8800();
extern "C" void __cdecl FUN_001e8830();
extern "C" int __cdecl _atexit(void (*)());
extern "C" void __cdecl FUN_003640b0();
struct Allocator_35edb0 {
    void Reg(void*, void*);
};
void __cdecl FUN_0035edb0() {
    (*(Allocator_35edb0*)&DAT_004e36c8).Reg((void*)FUN_001e8800, (void*)FUN_001e8830);
    _atexit((void (*)())FUN_003640b0);
}
