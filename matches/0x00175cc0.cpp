#include "compat/ptr.h"
extern "C" char DAT_00417f48[];
class Ref_175cc0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Helper_175cc0 {
  public:
    void Init();
    void InitSub();
};
class Teleport {
  public:
    hulk_intptr vptr;
    char pad[0x18];
    int value;
    Ref_175cc0* ref;
    char pad2[4];
    Helper_175cc0 sub;
    Teleport(int x, Ref_175cc0* r);
};
Teleport::Teleport(int x, Ref_175cc0* r) {
    ((Helper_175cc0*)this)->Init();
    vptr = ((hulk_intptr)DAT_00417f48);
    value = 0;
    ref = 0;
    sub.InitSub();
    value = x;
    if (r)
        r->Add();
    if (ref)
        ref->Release();
    ref = r;
}
