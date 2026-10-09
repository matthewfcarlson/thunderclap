struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
struct Obj {
    virtual void init();
    char pad[12];
    Inner* inner;
    Obj* build();
};
Obj* gObj;
extern void* alloc(unsigned int);
void FUN_002a3130() {
    if (gObj == 0) {
        Obj* p = (Obj*)alloc(0x20);
        if (p)
            gObj = p->build();
        else
            gObj = 0;
        gObj->init();
        gObj->inner->f6(0x444d4853, 0);
        gObj->inner->f6(0x54535441, 0);
        gObj->inner->f6(0x444d4c42, 1);
    }
}