struct Sub {
    void Helper();
};
struct Obj {
    char pad[16];
    Sub sub;
};
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};
struct B {
    char pad[0x18];
    V* p;
};
bool Target(Obj* a, B* b) {
    a->sub.Helper();
    b->p->f4(a);
    return true;
}