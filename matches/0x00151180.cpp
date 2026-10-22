// Same code shape as 0x00174c10 (propagated; names are from that function)
class Obj_151180 {
  public:
    virtual void A();
    virtual void B();
};
class Action_151180 {
  public:
    virtual void X();
    Action_151180();
};
class GroundSlideAction_151180 : public Action_151180 {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    int m1c;
    Obj_151180* m20;
    int m24;
    int m28;
    GroundSlideAction_151180(int, Obj_151180*);
};
GroundSlideAction_151180::GroundSlideAction_151180(int v, Obj_151180* p) : Action_151180() {
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