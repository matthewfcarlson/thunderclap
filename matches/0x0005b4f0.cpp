#include "compat/ptr.h"
#include "gen/global.h"

struct Obj_5b4f0 {
    char pad[0x104];
    int field;
};
struct ObjB_5b4f0 {
    char pad[0x330];
    Obj_5b4f0* f330;
    Obj_5b4f0* f334;
    Obj_5b4f0* Get() {
        if (f334)
            return f334;
        if (f330)
            return f330;
        return 0;
    }
};
struct ObjA_5b4f0 {
    ObjB_5b4f0* GetB();
};
struct Input_5b4f0 {
    ObjA_5b4f0* GetA();
};
struct CIntangibleAction_5b4f0 {
    CIntangibleAction* Init(int);
};
void* __cdecl FUN_0008d690(int);

int CGrappleIntangibleTrack::vfunc_12(int __p0) { Input_5b4f0 * p = (Input_5b4f0 *)__p0;

    if (p) {
        ObjA_5b4f0* a = p->GetA();
        if (a) {
            ObjB_5b4f0* b = a->GetB();
            if (b) {
                Obj_5b4f0* x = b->Get();
                if (x) {
                    int y = x->field;
                    if (y) {
                        CIntangibleAction* z = (CIntangibleAction*)FUN_0008d690(0x20);
                        if (z)
                            return (hulk_intptr)(((CIntangibleAction_5b4f0*)(z))->Init(y));
                    }
                }
            }
        }
    }
    return (int)(0);
}
