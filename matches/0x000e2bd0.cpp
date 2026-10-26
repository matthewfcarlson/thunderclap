#include "decls/data/game/global.h"
// data: kNegSmall = DAT_003f5cf0, kSmall = DAT_00405708

class FEControl {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual float GetX();
    virtual float GetY();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void Draw(float, float, float, float);
    virtual void vfunc_18();
};
void FEControl::vfunc_18() {
    float a = (GetY() * 0.5f) * DAT_003f5cf0;
    float b = (GetX() * 0.5f) * DAT_0040bf64;
    float c = (GetY() * 0.5f) * DAT_00405708;
    float d = GetY();
    d = d + c;
    float e = (GetX() * 0.5f) * DAT_0040c230;
    Draw(a, b, d, e);
}
