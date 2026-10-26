#include "gen/hulkfight.h"

#include "compat/ptr.h"
class Track_1a9ac0 {
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
    virtual int v10(int, int, int);
};
class Param_1a9ac0 {};
class NISAnimationAction_1a9ac0 {
  public:
    int helper(hulk_intptr, int);
};
extern "C" void* __cdecl FUN_0008d690(int);

hulk_intptr hulkfight::scenario::NISAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* x = FUN_0008d690(0x218);
    if (x)
        return ((NISAnimationAction_1a9ac0*)x)->helper((hulk_intptr)this, c);
    return 0;
}
