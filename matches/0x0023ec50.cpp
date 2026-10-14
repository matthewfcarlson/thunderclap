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
class Base_23ec50 {
  public:
    Base_23ec50();
    virtual void B();
};
class SpawnAction : public Base_23ec50 {
  public:
    SpawnAction(Owner_23ec50* owner, int value, Ref_23ec50* ref);
    virtual void V();
    char p4[0x18];
    int m1c;
    int m20;
    int m24;
    Inner_23ec50 inner;
    int m50;
    char flag;
};
SpawnAction::SpawnAction(Owner_23ec50* owner, int value, Ref_23ec50* ref) : Base_23ec50(), m24(0), inner() {
    m50 = 0;
    flag = 0;
    m20 = (int)owner;
    owner->F();
    m1c = value;
    if (ref)
        ref->Add();
    if (m24)
        ((Ref_23ec50*)m24)->Release();
    m24 = (int)ref;
}
