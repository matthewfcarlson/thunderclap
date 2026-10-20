#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_00431700[];
class Ref_2f8820 {
  public:
    virtual void Release(int);
};
struct Obj_2f8820 {
    void* vptr;
    char pad[4];
    Ref_2f8820* ref;
};
void __fastcall FUN_002f8820(Obj_2f8820* p, void*) {
    p->vptr = (void*)((hulk_intptr)DAT_00431700);
    if (p->ref) {
        p->ref->Release(1);
        p->ref = 0;
    }
    p->vptr = (void*)((hulk_intptr)DAT_003f6098);
}