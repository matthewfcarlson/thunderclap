struct Ref {
    virtual void f0();
    virtual void f1();
};
struct Child {
    virtual void f0();
};
struct H;
struct State {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void f13(Child*);
    virtual void a14();
    virtual void a15();
    virtual void a16();
    char pad[0x10 - 4];
    Ref* current;
    char pad2[0x9c - 0x14];
    H* host;
};
struct H {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13(Child*);
};
void State::f13(Child* p) {
    if (p)
        p->f0();
    Ref*& cur = current;
    if (cur)
        cur->f1();
    cur = (Ref*)p;
    host->a13(p);
}
