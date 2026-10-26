#include "decls/data/engine/core.h"
// data: fileName = DAT_0042bc9c

extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
void __cdecl target(int param_1, int param_2) {
    Init(((char*)&DAT_0052a1e8));
    Register(((char*)&DAT_0052a204), 0x168, param_1, 0, param_2, DAT_0042bc9c, 4);
}
