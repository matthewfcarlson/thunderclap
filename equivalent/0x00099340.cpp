// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// FUN_00099340 @ 0x00099340
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "gen/global.h"
#include "gen/owners.h"
void *thunk_FUN_0008d690(unsigned int size);

struct CScriptCamera_nv_99340 {
    CScriptCamera *FUN_000ac7d0();
};

class Panel_99340 {
public:
    char pad0[0xc4];
    CScriptCamera *range;
    void FUN_00099340();
};

void Panel_99340::FUN_00099340()
{
    if (range == 0) {
        CScriptCamera *r = (CScriptCamera *)thunk_FUN_0008d690((int)sizeof(CScriptCamera));
        if (r != 0)
            r = ((CScriptCamera_nv_99340*)(((CScriptCamera*)(r))))->FUN_000ac7d0();
        range = r;
        r->vfunc_0();
        range->vfunc_28();
    }
    ((owners::Thing_a90f0 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a90f0(0, 0);
    ((owners::C_a9130 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9130(0, 0);
    ((owners::C_a9110 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9110(0, 1.0f);
    ((owners::Thing_a90f0 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a90f0(1, 0);
    ((owners::C_a9130 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9130(1, 0);
    ((owners::C_a9110 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9110(1, 1.0f);
}
