#include "compat/ptr.h"
class Inner_23ec50 {
  public:
    Inner_23ec50();
    char d[0x28];
};
class Owner_23ec50 {
  public:
    virtual void F();
};
class Ref_23ec50 {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_23ec50 {
  public:
    Action_23ec50();
    virtual void B();
};
class SpawnAction : public Action_23ec50 {
  public:
    SpawnAction(Owner_23ec50* owner, int value, Ref_23ec50* ref);
    virtual void V();
    char p4[0x18];
    int m1c;
    hulk_intptr m20;
    hulk_intptr m24;
    Inner_23ec50 inner;
    int m50;
    char flag;
};
SpawnAction::SpawnAction(Owner_23ec50* owner, int value, Ref_23ec50* ref) : Action_23ec50(), m24(0), inner() {
    m50 = 0;
    flag = 0;
    m20 = (hulk_intptr)owner;
    owner->F();
    m1c = value;
    if (ref)
        ref->Add();
    if (m24)
        ((Ref_23ec50*)m24)->Release();
    m24 = (hulk_intptr)ref;
}
