#include "decls/data/engine/core.h"
// data: tag = DAT_0042b904

extern "C" void __cdecl Init(void*);
extern "C" void __cdecl Register(void*, int, int, int, int, const char*, int);
void Target(int a, int b) {
    Init(((char*)&DAT_0052a1c8));
    Register(((char*)&DAT_0052a1e4), 0x114, a, 0, b, DAT_0042b904, 4);
}
