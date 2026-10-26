// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 8/8)
// CCollisionTrack::vfunc_10 @ 0x0005daf0
#include "compat/ptr.h"
#include "gen/global.h"

extern char DAT_00494b44[];
extern char DAT_00494b60[];
void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
void* __cdecl FUN_0008d690(unsigned size);
struct Index_5daf0 { int FUN_0027b200(unsigned lo, unsigned hi); };
struct Lookup_5daf0 { Index_5daf0* FUN_002226b0(); };
struct Owner_5daf0 { Lookup_5daf0* FUN_00059a40(); };
struct Holder_5daf0 { Owner_5daf0* FUN_000592a0(); };
struct CCollisionAction_5daf0 { CCollisionAction_5daf0* FUN_00019380(void* a, void* self, Holder_5daf0* h, int index); };

hulk_intptr CCollisionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * c = (void *)__p2;

    Holder_5daf0* h = (Holder_5daf0*)FUN_00344e74(c, 0, DAT_00494b44, DAT_00494b60, 0);
    Lookup_5daf0* lk = h ? h->FUN_000592a0()->FUN_00059a40() : 0;
    if (!lk) return (int)(0);
    unsigned arg1_ = (*(unsigned int *)&this->f_1c);
    unsigned arg2_ = (*(unsigned int *)&this->f_18);
    int index = lk->FUN_002226b0()->FUN_0027b200(arg2_, arg1_);
    if (index == 0xffff) return (int)(0);
    CCollisionAction_5daf0* item = (CCollisionAction_5daf0*)FUN_0008d690(0x4c);
    if (!item) return (int)(0);
    return (hulk_intptr)(item->FUN_00019380(a, this, h, index));
}
