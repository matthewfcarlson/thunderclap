struct Global_293bf0 {
    void a();
    void b(unsigned);
};
extern Global_293bf0 g_293bf0;
struct Obj_293bf0 {
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
struct Target_293bf0 {
    Obj_293bf0* obj;
    void run(unsigned);
};
char g52c2d8[4];
void Target_293bf0::run(unsigned arg) {
    g_293bf0.a();
    g_293bf0.b(arg);
    obj->f17(0, g52c2d8);
}