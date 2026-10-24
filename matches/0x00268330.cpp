#include "gen/core.h"

#include "compat/ptr.h"
extern "C" char hulk_at_003f6094[];

void core::IRefCount::FUN_00268330() {
    *(hulk_intptr*)this = ((hulk_intptr)(hulk_at_003f6094 + 0x4));
}
