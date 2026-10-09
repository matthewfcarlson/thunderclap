class Item {
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
class Mgr {
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
struct Root {
    Mgr* m;
};
extern Root* gRoot;
class Target {
    char pad[0xbc];
    Item* member;

  public:
    void helper(Item*, int);
    void fn(Item*, int, int);
};
void Target::fn(Item* p, int x, int y) {
    if (p) {
        gRoot->m->p(0);
        helper(p, y);
        p->i((int)member, x);
        gRoot->m->q(0);
    }
}