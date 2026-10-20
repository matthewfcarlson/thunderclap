#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042aee4[];
class Ref_266690 {
  public:
    virtual void A();
    virtual void Release();
};
class LoadRequest {
  public:
    virtual void A();
    char pad14[0x14];
    Ref_266690* a;
    Ref_266690* b;
    char pad20[0x104];
    Ref_266690* c;
    void Destroy();
};
void LoadRequest::Destroy() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042aee4);
    if (a)
        a->Release();
    if (c)
        c->Release();
    if (b)
        b->Release();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
}
