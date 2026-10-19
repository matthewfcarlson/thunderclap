#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_00066930();
extern "C" void __cdecl FUN_00066a00();
class C_363bf0 {
  public:
    void init(void*, void*);
};
extern "C" void __cdecl FUN_00363bf0(void) {
    ((C_363bf0*)((int)DAT_004dc988))->init((void*)((int)(void (__cdecl*)())&FUN_00066930), (void*)((int)DAT_004dc988));
    ((C_363bf0*)((int)DAT_004dc96c))->init((void*)((int)(void (__cdecl*)())&FUN_00066a00), (void*)((int)DAT_004dc96c));
    ((C_363bf0*)((int)DAT_004dc950))->init((void*)((int)(void (__cdecl*)())&FUN_00066930), (void*)((int)DAT_004dc950));
}