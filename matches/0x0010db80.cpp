#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern void* __fastcall FUN_000592a0(void*);
extern void __fastcall FUN_00059a30(void*);
extern void* FUN_000678d0();
extern void __fastcall FUN_00067730(void*);

bool hulkfight::ai::HulkAction::vfunc_5(hulk_intptr param_2, int param_3) {
    if (param_2 == 0) {
        void* p = FUN_000592a0(*(void**)((char*)this + 0x20));
        FUN_00059a30(p);
        p = FUN_000678d0();
        FUN_00067730(p);
    }
    return true;
}
