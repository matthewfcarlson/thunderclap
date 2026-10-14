class Obj_174c10 {
  public:
    virtual void A();
    virtual void B();
};
class Base_174c10 {
  public:
    virtual void X();
    Base_174c10();
};
class FootPivotAction : public Base_174c10 {
  public:
    virtual void A();
    virtual void B();
    char pad[0x18];
    int m1c;
    Obj_174c10* m20;
    int m24;
    int m28;
    FootPivotAction(int, Obj_174c10*);
};
FootPivotAction::FootPivotAction(int v, Obj_174c10* p) : Base_174c10() {
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