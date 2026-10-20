class C3_1489d0 {
  public:
    void Release();
};
class C2_1489d0 {
  public:
    C3_1489d0* Get();
};
class Motion_1489d0 {
  public:
    C2_1489d0* Get();
};
class BaseAction_1489d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int f(int, int);
};
class Obj_1489d0 {
  public:
    virtual void A();
    virtual void B();
};
class Sub_1489d0 {
  public:
    Obj_1489d0* cur;
    void Init(int, int);
    void Set(int);
    void Set2(int);
    int Finish();
};
class GrappleHitReactionAction : public BaseAction_1489d0 {
  public:
    char pad4[0x1c];
    Motion_1489d0* motion;
    Sub_1489d0 sub;
    char pad28[0x24];
    Obj_1489d0* old;
    int count;
    char flag;
    virtual int f(int x, int y);
};
int GrappleHitReactionAction::f(int x, int y) {
    if (!x && !flag)
        sub.Init(count, y);
    Obj_1489d0* p = old;
    Obj_1489d0* q = sub.cur;
    flag = 0;
    if (p != q)
        motion->Get()->Get()->Release();
    sub.Set(x);
    if (x == count - 1)
        sub.Set2(1);
    Obj_1489d0* r = sub.cur;
    if (r)
        r->A();
    if (old)
        old->B();
    old = r;
    return sub.Finish();
}
