struct Obj_271530 {
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
};
struct A_271530 {
    Obj_271530* p;
};
extern void __cdecl FUN_00271410(A_271530*, int, int, int);
void __cdecl FUN_00271530(A_271530* a, int b, int c, int d) {
    FUN_00271410(a, b, c, d);
    if (a->p)
        a->p->f22();
}
