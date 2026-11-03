#include "decls/data/game/global.h"
// data: gZero_670e0 = DAT_003f32e0

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00066980();
class H {
  public:
    void* lookup(hulk_uintptr, unsigned int);
};
float owners::C_670e0::FUN_000670e0(hulk_uintptr x) {
    H* h = (H*)((char*)this + 0x2f4);
    void* p = h->lookup(((hulk_intptr)(void (__cdecl*)())&FUN_00066980), ((unsigned int)x));
    if (!p)
        return DAT_003f32e0;
    return *(float*)((char*)p + 0x18);
}