#include "compat/ptr.h"
extern "C" char DAT_0040d884[];
extern "C" void _ReadWriteBarrier();
struct Ref_10b9d0 {
    virtual void f0();
    virtual void Release();
};
void __fastcall BaseDestroy(void*);
struct FaceTargetAction {
    hulk_intptr vptr;
    char pad[0x18];
    int field1c;
    Ref_10b9d0* field20;
    void Cleanup();
};
void FaceTargetAction::Cleanup() {
    vptr = ((hulk_intptr)DAT_0040d884);
    _ReadWriteBarrier();
    Ref_10b9d0* r = field20;
    if (r) {
        r->Release();
        field20 = 0;
    }
    if (field1c)
        field1c = 0;
    BaseDestroy(this);
}
