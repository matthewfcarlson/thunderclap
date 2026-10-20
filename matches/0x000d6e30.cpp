#include "compat/ptr.h"
extern "C" char DAT_0040b370[];
struct Ref_d6e30 {
    virtual void f0();
    virtual void Release();
};
class COverlayManager {
  public:
    virtual void v0();
    Ref_d6e30* a;
    char pad[0x24];
    Ref_d6e30* b;
    void clear();
};
void COverlayManager::clear() {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0040b370);
    Ref_d6e30* x = *(Ref_d6e30* volatile*)&a;
    if (x) {
        x->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
}
