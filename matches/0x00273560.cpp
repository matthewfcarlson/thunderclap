typedef unsigned int u32;
struct Obj {
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
    virtual u32 f13();
};
extern char gObjStorage[4];
extern Obj* gObj;
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
u32 target() {
    FUN_0026d850(gObjStorage);
    u32 r = gObj->f13();
    FUN_0026d840(gObjStorage);
    return r;
}