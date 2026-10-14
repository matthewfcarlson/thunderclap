struct Ref_27d680 {
    virtual void f0();
    virtual void f1();
};
struct Child_27d680 {
    virtual void f0();
};
struct H;
struct State_27d680 {
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
    virtual void f13(Child_27d680*);
    virtual void a14();
    virtual void a15();
    virtual void a16();
    char pad[0x10 - 4];
    Ref_27d680* current;
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
    virtual void a13(Child_27d680*);
};
void State_27d680::f13(Child_27d680* p) {
    if (p)
        p->f0();
    Ref_27d680*& cur = current;
    if (cur)
        cur->f1();
    cur = (Ref_27d680*)p;
    host->a13(p);
}
