class Sub {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void a(int);
    virtual void v9();
    virtual void b(int);
};
class Mgr {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual Sub* get();
};
struct Inner {
    char p[0x175c];
    Mgr* mgr;
};
struct Obj {
    char p[4];
    Inner* in;
    char q[0x9a0];
    char flag;
    char r[3];
    int val;
};
class C {
  public:
    void Fn();
    char p[0x2218];
    Obj* cur;
    int saved;
};
void C::Fn() {
    Obj* o = cur;
    if (o) {
        o->flag = 0;
        Mgr* m = o->in->mgr;
        if (m) {
            Sub* s = m->get();
            if (s) {
                s->a(0);
                s->b(2);
            }
        }
        saved = cur->val;
        cur = 0;
    }
}