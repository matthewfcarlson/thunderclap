class C3 {
  public:
    void Release();
};
class C2 {
  public:
    C3* Get();
};
class Motion {
  public:
    C2* Get();
};
class BaseAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(int, int);
};
class Obj {
  public:
    virtual void A();
    virtual void B();
};
class Sub {
  public:
    Obj* cur;
    void Init(int, int);
    void Set(int);
    void Set2(int);
    void Finish();
};
class GrappleHitReactionAction : public BaseAction {
  public:
    char pad4[0x1c];
    Motion* motion;
    Sub sub;
    char pad28[0x24];
    Obj* old;
    int count;
    char flag;
    virtual void f(int x, int y);
};
void GrappleHitReactionAction::f(int x, int y) {
    if (!x && !flag)
        sub.Init(count, y);
    Obj* p = old;
    Obj* q = sub.cur;
    flag = 0;
    if (p != q)
        motion->Get()->Get()->Release();
    sub.Set(x);
    if (x == count - 1)
        sub.Set2(1);
    Obj* r = sub.cur;
    if (r)
        r->A();
    if (old)
        old->B();
    old = r;
    sub.Finish();
}
