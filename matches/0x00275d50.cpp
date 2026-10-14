// Same code shape as 0x00273560 (propagated; names are from that function)
typedef unsigned int u32_275d50;
struct Obj_275d50 {
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
    virtual u32_275d50 f13();
};
extern char gObjStorage[4];
extern Obj_275d50* gObj_275d50;
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
u32_275d50 target() {
    FUN_0026d850(gObjStorage);
    u32_275d50 r = gObj_275d50->f13();
    FUN_0026d840(gObjStorage);
    return r;
}