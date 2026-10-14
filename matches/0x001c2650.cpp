class Item_1c2650 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i(int, int);
};
class Mgr_1c2650 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p(int);
    virtual void q(int);
};
struct Root_1c2650 {
    Mgr_1c2650* m;
};
extern Root_1c2650* gRoot_1c2650;
class Target_1c2650 {
    char pad[0xbc];
    Item_1c2650* member;

  public:
    void helper(Item_1c2650*, int);
    void fn(Item_1c2650*, int, int);
};
void Target_1c2650::fn(Item_1c2650* p, int x, int y) {
    if (p) {
        gRoot_1c2650->m->p(0);
        helper(p, y);
        p->i((int)member, x);
        gRoot_1c2650->m->q(0);
    }
}