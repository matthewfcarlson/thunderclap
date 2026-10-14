struct Obj_24970 {
    char pad[0x20a8];
    int a;
    int b;
};
class Context {
  public:
    Obj_24970* Find(int);
};
class Manager_24970 {
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
    char pad[0x40];
    Context* ctx;
};
class Thing_24970 {
  public:
    Manager_24970* mgr;
    char pad4[8];
    int count;
    int items[1];
    bool Set(int);
};
bool Thing_24970::Set(int value) {
    if (value < -1 || value >= 5)
        return false;
    int n = count;
    for (int i = 0; i < n; ++i) {
        Context* c = mgr->ctx;
        Obj_24970* o = c->Find(items[i]);
        if (o) {
            o->b = o->a;
            o->a = value;
        }
        n = count;
    }
    return true;
}