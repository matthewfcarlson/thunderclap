class Obj_1d4c0 {
  public:
    virtual void F();
    virtual void G();
};
class Helper_1d4c0 {
  public:
    float Get();
};
class Base_1d4c0 {
  public:
    Base_1d4c0();
    virtual void Z();
};
class CAutoTargetAction_1d4c0 : public Base_1d4c0 {
  public:
    CAutoTargetAction_1d4c0(Obj_1d4c0* o);
    virtual void A();
    virtual void B();
    char pad[0x18];
    Obj_1d4c0* ref;
};
CAutoTargetAction_1d4c0::CAutoTargetAction_1d4c0(Obj_1d4c0* o) : Base_1d4c0() {
    ref = 0;
    if (o)
        o->F();
    if (ref)
        ref->G();
    ref = o;
}
class CAutoTargetAction : public CAutoTargetAction_1d4c0 {
  public:
    CAutoTargetAction(Helper_1d4c0* h, Obj_1d4c0* o);
    virtual void C();
    virtual void D();
    Helper_1d4c0* x;
    int y;
    int z;
    float f;
};
CAutoTargetAction::CAutoTargetAction(Helper_1d4c0* h, Obj_1d4c0* o) : CAutoTargetAction_1d4c0(o) {
    y = 0;
    z = 0;
    x = h;
    f = h->Get();
}
