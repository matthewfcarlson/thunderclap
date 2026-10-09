struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
struct Host {
    char pad[0xbc];
    int value;
    void target(Obj*, int, int);
};
void __stdcall helper(Obj*, int);
void Host::target(Obj* p, int a, int b) {
    if (p) {
        helper(p, b);
        p->f8(value, a);
    }
}