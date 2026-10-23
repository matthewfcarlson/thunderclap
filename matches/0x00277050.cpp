// Same code shape as 0x00274af0 (propagated; names are from that function)
struct Obj_277050 {
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
extern Obj_277050* DAT_0052a224;
extern char DAT_0052a208[];
void FUN_0026d830(void*);
void target() {
    char a[4], b[4], c[4];
    FUN_0026d830(DAT_0052a208);
    DAT_0052a224->f14(a, b, c);
    DAT_0052a224->f1();
    DAT_0052a224 = 0;
}