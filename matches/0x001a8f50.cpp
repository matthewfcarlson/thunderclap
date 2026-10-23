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
    int Call(hulkfight::scenario::EffectTrack*, int);
};
extern EffectAction_1a8f50* GetThing(int);

int hulkfight::scenario::EffectTrack::vfunc_10(int x, int , int ) {
    EffectAction_1a8f50* p = GetThing(0x6c);
    if (p)
        return p->Call(this, x);
    return 0;
}
