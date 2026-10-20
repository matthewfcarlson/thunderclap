#include "compat/ptr.h"
#include "decls/address.h"
extern void* gCursorLocators[2];

void FUN_0035dad0() {
    unsigned long long r = FUN_0027b020("TextInputCursorLocators");
    gCursorLocators[0] = (void*)((hulk_uintptr)r);
    gCursorLocators[1] = (void*)((hulk_uintptr)(r >> 32));
}
