#include "compat/ptr.h"
#include "decls/data/engine/om.h"

extern "C" char DAT_0042aad0[];
typedef unsigned int u32_260c70;
struct ThisCall_002584d0 {
    void Init(void*, void*, int, int);
};
extern "C" void* __fastcall FUN_00260c70(void* p, void* edx) {
    HULK_SIZE32(OmDynAttrString, 0x24);
    ((ThisCall_002584d0*)(p))->Init((void*)((hulk_intptr)DAT_004e58d0), (void*)((hulk_intptr)DAT_004e58c8), (int)sizeof(OmDynAttrString), (int)__alignof(OmDynAttrString));
    *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042aad0);
    return p;
}