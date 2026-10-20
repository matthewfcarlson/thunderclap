#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042e7f0[];
class Ref_2bc4d0 {
  public:
    virtual void A();
    virtual void B();
};
class OldBillboardObjectLoader : public Ref_2bc4d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual OldBillboardObjectLoader* v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x14 - sizeof(Ref_2bc4d0)];
    Ref_2bc4d0* volatile mRef;
};
extern void __cdecl thunk(OldBillboardObjectLoader*);
OldBillboardObjectLoader* OldBillboardObjectLoader::v2(int flags) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0042e7f0);
    Ref_2bc4d0* r = mRef;
    if (r) {
        r->B();
        mRef = 0;
    }
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        thunk(this);
    return this;
}