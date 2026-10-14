struct Obj_274af0 {
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
    virtual void f14(void*, void*, void*);
};
extern Obj_274af0* gObj_274af0;
extern char gData_274af0[];
void init(void*);
void target() {
    char a[4], b[4], c[4];
    init(gData_274af0);
    gObj_274af0->f14(a, b, c);
    gObj_274af0->f1();
    gObj_274af0 = 0;
}