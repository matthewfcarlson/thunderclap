#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
// data: gFunction = DAT_004caa24, gValue_238350 = DAT_004e5c1c, gZero_238350 = DAT_003f32e0

#include "compat/ptr.h"
typedef float(__cdecl* Callback_238350)(unsigned int, unsigned int);
hulk_freg __cdecl FUN_00238350(unsigned int param) {
    if ((*(Callback_238350*)&DAT_004caa24) == 0)
        return DAT_003f32e0;
    return (*(Callback_238350*)&DAT_004caa24)(param, (*(unsigned int*)&DAT_004e5c1c));
}