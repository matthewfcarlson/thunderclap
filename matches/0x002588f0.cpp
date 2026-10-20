#include "compat/ptr.h"
#include "gen/om.h"
#include "decls/data/engine/om.h"

extern "C" void __cdecl helper(void*, om::Type*);

void om::Type::vfunc_1() {
    helper((void*)((hulk_intptr)((char*)&DAT_004cd1a8)), this);
}
