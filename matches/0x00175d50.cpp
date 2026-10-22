#include "compat/ptr.h"
extern "C" char DAT_00417f64[];
class Ref_175d50 {
  public:
    virtual void F();
};
class Link_175d50 {
  public:
    virtual void A();
    virtual void B();
};
class Action_175d50 {
  public:
    void Init();
};
class Part_175d50 {
  public:
    void Init();
};
class SyncToLocatorAction_175d50 : public Action_175d50 {
  public:
    char pad0[0x1c];
    int mA;
    Link_175d50* mLink;
    char pad24[4];
    Part_175d50 part;
    char pad2c[4];
    int mX;
    int mY;
    char pad38[12];
    int mZ;
    SyncToLocatorAction_175d50* Func(int a, Ref_175d50* r);
};
SyncToLocatorAction_175d50* SyncToLocatorAction_175d50::Func(int a, Ref_175d50* r) {
    Init();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00417f64);
    mA = 0;
    mLink = 0;
    part.Init();
    mX = 0;
    mY = 0;
    mZ = 0;
    mA = a;
    if (r)
        r->F();
    if (mLink)
        mLink->B();
    mLink = (Link_175d50*)r;
    return this;
}