typedef unsigned __int64 U64;
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void run(int);
};
struct Obj {
    char pad[0x1ca0];
    V* v;
};
extern "C" U64 __cdecl make(unsigned, unsigned, unsigned);
class Owner {
  public:
    Obj* lookup(U64);
    void fn(unsigned a, int b);
};
void Owner::fn(unsigned a, int b) {
    Obj* p = lookup(make(a, 0, 0));
    if (!p)
        return;
    V* v = p->v;
    if (!v)
        return;
    v->run(b);
}
