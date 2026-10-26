#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Track_1a8f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};
class Param_1a8f50 {};
class EffectAction_1a8f50 {
  public:
    int Call(hulkfight::scenario::EffectTrack*, hulk_intptr);
};
extern EffectAction_1a8f50* GetThing(int);

hulk_intptr hulkfight::scenario::EffectTrack::vfunc_10(hulk_intptr x, hulk_intptr , hulk_intptr ) {
    EffectAction_1a8f50* p = GetThing(0x6c);
    if (p)
        return p->Call(this, x);
    return 0;
}
