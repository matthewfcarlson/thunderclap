struct Block {
    unsigned long v[16];
};
class Inner {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(Block b);
};
class Store {
  public:
    void F670(int x);
    void F700(Block* b, unsigned long x);
};
class Obj {
  public:
    char p[0xa0];
    Store* store;
    char q[0x78];
    Inner* inner;
    char r[0x38];
    unsigned long x, y, z;
    void F7dde0(Block* b);
    void run(Block b, unsigned long arg);
};
void Obj::run(Block b, unsigned long arg) {
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
