#include "decls/data/game/global.h"
// data: gZero_670e0 = DAT_003f32e0

#include "compat/ptr.h"
extern "C" void __cdecl FUN_00066980();
class H {
  public:
    void* lookup(hulk_uintptr, unsigned int);
};
class C_670e0 {
  public:
    char pad[0x2f4];
    float f(unsigned int);
};
float C_670e0::f(unsigned int x) {
    H* h = (H*)((char*)this + 0x2f4);
    void* p = h->lookup(((hulk_intptr)(void (__cdecl*)())&FUN_00066980), x);
    if (!p)
        return DAT_003f32e0;
    return *(float*)((char*)p + 0x18);
}