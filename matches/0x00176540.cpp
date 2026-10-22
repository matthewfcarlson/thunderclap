class Ref_176540 {
  public:
    virtual void A();
    virtual void B();
};
class Action_176540 {
  public:
    Action_176540();
    virtual void V0();
    char pad[0x18];
};
class SurfAction_176540 : public Action_176540 {
  public:
    int a;
    Ref_176540* b;
    int c[6];
    float f;
    int d;
    SurfAction_176540(int, Ref_176540*);
    virtual void V0();
};
SurfAction_176540::SurfAction_176540(int x, Ref_176540* r) : Action_176540() {
    int* q = &a;
    *q = 0;
    b = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
    f = 1.0f;
    d = 0;
    a = x;
    if (r)
        r->A();
    if (b)
        b->B();
    b = r;
}
