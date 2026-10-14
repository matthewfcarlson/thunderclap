class Obj_98480 {
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
    virtual void f29();
    virtual void f30();
    virtual void f31(unsigned int);
};
class Owner_98480 {
  public:
    char pad[0x170];
    Obj_98480* a;
    Obj_98480* b;
    unsigned char flag;
    Obj_98480* go(unsigned int);
};
Obj_98480* Owner_98480::go(unsigned int arg) {
    Obj_98480* result = b;
    if (a) {
        if (flag)
            a->f31(arg);
        a->f1();
        a = 0;
    }
    if (b) {
        b->f1();
        b = 0;
    }
    return result;
}