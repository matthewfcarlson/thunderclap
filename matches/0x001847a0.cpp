#include "compat/ptr.h"
extern "C" char DAT_00419774[];
class Ref_1847a0 {
  public:
    virtual void A();
    virtual void Release();
};
class ShieldArcAction {
  public:
    volatile hulk_intptr vft;
    char pad[0x18];
    int m1c;
    Ref_1847a0* volatile m20;
    void Cleanup();
    void Finish();
};
void ShieldArcAction::Cleanup() {
    vft = ((hulk_intptr)DAT_00419774);
    Ref_1847a0* p = m20;
    if (p) {
        p->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Finish();
}