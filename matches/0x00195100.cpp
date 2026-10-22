class Action_195100 {
  public:
    virtual void F();
    virtual void G();
    char pad[0x18];
    Action_195100();
};
class FireProjectileAction_195100 : public Action_195100 {
  public:
    int a;
    Action_195100* b;
    int c;
    int d;
    int e;
    int f;
    FireProjectileAction_195100(int x, Action_195100* p);
    virtual void F();
    virtual void G();
};
FireProjectileAction_195100::FireProjectileAction_195100(int x, Action_195100* p) : Action_195100() {
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (p)
        p->F();
    if (b)
        b->G();
    b = p;
}
