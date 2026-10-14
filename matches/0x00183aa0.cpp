// Same code shape as 0x00174c10 (propagated; names are from that function)
class Obj_183aa0 {
  public:
    virtual void A();
    virtual void B();
};
class Base_183aa0 {
  public:
    virtual void X();
    Base_183aa0();
};
class FootPivotAction : public Base_183aa0 {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    int m1c;
    Obj_183aa0* m20;
    int m24;
    int m28;
    FootPivotAction(int, Obj_183aa0*);
};
FootPivotAction::FootPivotAction(int v, Obj_183aa0* p) : Base_183aa0() {
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