// Same code shape as 0x00174c10 (propagated; names are from that function)
class Obj_135ef0 {
  public:
    virtual void A();
    virtual void B();
};
class Action_135ef0 {
  public:
    virtual void X();
    Action_135ef0();
};
class FlyingAutoTargetAction_135ef0 : public Action_135ef0 {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    int m1c;
    Obj_135ef0* m20;
    int m24;
    int m28;
    FlyingAutoTargetAction_135ef0(int, Obj_135ef0*);
};
FlyingAutoTargetAction_135ef0::FlyingAutoTargetAction_135ef0(int v, Obj_135ef0* p) : Action_135ef0() {
    volatile int* q = &m1c;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    m1c = v;
    if (p)
        p->A();
    if (m20)
        m20->B();
    m20 = p;
}