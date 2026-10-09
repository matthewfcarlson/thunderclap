class Inner {
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
    virtual void o(int);
};
struct Mid {
    char pad[0x10];
    Inner* q;
};
struct Entry {
    Mid* p;
    char pad[16];
};
class movie_RenderStrategyBink {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad[0x30 - 4];
    int index;
    Entry entries[1];
    char flag;
};
void movie_RenderStrategyBink::v5() {
    Mid* m = entries[index].p;
    m->q->o(0);
    ++index;
    flag = 0;
}
