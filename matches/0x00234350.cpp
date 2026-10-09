class Param;
class Item {
  public:
    virtual void a(int);
    virtual void b();
    virtual bool c();
    virtual void d();
    virtual void e();
    virtual void f(Param*, int, int);
};
class Param {
  public:
    virtual Item* Get(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    bool vfunc_4(int, int);
};
bool Param::vfunc_4(int p1, int p2) {
    int i = 0;
    Item* x = Get(0);
    while (x) {
        if (!x->c())
            x->f(this, p1, p2);
        ++i;
        x = Get(i);
    }
    return true;
}