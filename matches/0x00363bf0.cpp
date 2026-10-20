#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_00066930();
extern "C" void __cdecl FUN_00066a00();
class C_363bf0 {
  public:
    void init(void*, void*);
};
extern "C" void __cdecl FUN_00363bf0(void) {
    ((C_363bf0*)((hulk_intptr)DAT_004dc988))->init((void*)((hulk_intptr)(void (__cdecl*)())&FUN_00066930), (void*)((hulk_intptr)DAT_004dc988));
    ((C_363bf0*)((hulk_intptr)DAT_004dc96c))->init((void*)((hulk_intptr)(void (__cdecl*)())&FUN_00066a00), (void*)((hulk_intptr)DAT_004dc96c));
    ((C_363bf0*)((hulk_intptr)DAT_004dc950))->init((void*)((hulk_intptr)(void (__cdecl*)())&FUN_00066930), (void*)((hulk_intptr)DAT_004dc950));
}