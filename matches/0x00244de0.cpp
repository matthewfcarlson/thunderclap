#include "compat/ptr.h"
#include "gen/om.h"
#include "decls/data/engine/om.h"

namespace om {
} // namespace om
extern void __cdecl FUN_00244610(void*, void*);
extern void __cdecl FUN_002446d0(void*, void*);
void om::EntityType::vfunc_1() {
    FUN_00244610(*(void**)((hulk_intptr)((char*)&DAT_004cc084)), this);
    FUN_002446d0(*(void**)((hulk_intptr)((char*)&DAT_004cc088)), this);
    int x = *(volatile int*)((hulk_intptr)DAT_004e5f10);
    --x;
    *(volatile int*)((hulk_intptr)DAT_004e5f10) = x;
}
