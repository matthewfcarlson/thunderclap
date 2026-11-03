#include "decls/data/engine/core.h"
// data: fileName = DAT_0042bc9c

extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
extern "C" void __cdecl FUN_00275d20(int a, int b) {
    Init(((char*)&DAT_0052a1e8));
    Register(((char*)&DAT_0052a204), 0x168, a, 0, b, DAT_0042bc9c, 4);
}
