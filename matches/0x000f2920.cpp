// Same code shape as 0x000f27a0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
extern void* Alloc(hulk_uintptr);
struct FEBillboardAnimation_nv_f2920 {
    int Create(int, int);
};
hulk_intptr owners::Holder_f2920::FUN_000f2920(hulk_intptr arg) {
    if (data == 0)
        return 0;
    FEBillboardAnimation* obj = (FEBillboardAnimation*)Alloc(100);
    int result;
    if (obj != 0)
        result = ((FEBillboardAnimation_nv_f2920*)(((FEBillboardAnimation*)(obj))))->Create(data, ((int)arg));
    else
        result = 0;
    int i;
    for (i = 0; i < 32; ++i) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
    }
    return result;
}
