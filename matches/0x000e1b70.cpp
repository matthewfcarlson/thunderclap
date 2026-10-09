struct Inner {
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29(void*);
};
struct Holder {
    char pad[4];
    Inner* p;
};
struct FEDoMenu {
    virtual void f0();
    virtual void vfunc_1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad[12];
    Holder* m10;
    char pad2[0x34 - 0x14];
};
void FEDoMenu::vfunc_1() {
    m10->p->f29((char*)this + 0x34);
}