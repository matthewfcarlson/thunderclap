// Same code shape as 0x00293bf0 (propagated; names are from that function)
struct Global_293c20 {
    void a();
    void b(unsigned);
};
extern Global_293c20 g_293c20;
struct Obj_293c20 {
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
    virtual void f17(unsigned, void*);
};
struct Target_293c20 {
    Obj_293c20* obj;
    void run(unsigned);
};
char g52c2d8[4];
void Target_293c20::run(unsigned arg) {
    g_293c20.a();
    g_293c20.b(arg);
    obj->f17(0, g52c2d8);
}