struct Block_1d6b60 {
    unsigned long v[16];
};
class Inner_1d6b60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(Block_1d6b60 b);
};
class Store {
  public:
    void F670(int x);
    void F700(Block_1d6b60* b, unsigned long x);
};
class Obj_1d6b60 {
  public:
    char p[0xa0];
    Store* store;
    char q[0x78];
    Inner_1d6b60* inner;
    char r[0x38];
    unsigned long x, y, z;
    void F7dde0(Block_1d6b60* b);
    void run(Block_1d6b60 b, unsigned long arg);
};
void Obj_1d6b60::run(Block_1d6b60 b, unsigned long arg) {
    inner->g(b);
    F7dde0(&b);
    Store* s = store;
    if (s) {
        s->F670(2);
        s->F700(&b, arg);
    }
    x = b.v[12];
    y = b.v[13];
    z = b.v[14];
}
