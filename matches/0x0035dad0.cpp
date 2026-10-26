#include "decls/data/game/global.h"
// data: gCursorLocators = DAT_004de708

#include "compat/ptr.h"
#include "decls/address.h"

void FUN_0035dad0() {
    unsigned long long r = FUN_0027b020("TextInputCursorLocators");
    ((void**)&DAT_004de708)[0] = (void*)((hulk_uintptr)r);
    ((void**)&DAT_004de708)[1] = (void*)((hulk_uintptr)(r >> 32));
}
