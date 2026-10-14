struct Inner_2a3130 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
struct Obj_2a3130 {
    virtual void init();
    char pad[12];
    Inner_2a3130* inner;
    Obj_2a3130* build();
};
Obj_2a3130* gObj_2a3130;
extern void* alloc(unsigned int);
void FUN_002a3130() {
    if (gObj_2a3130 == 0) {
        Obj_2a3130* p = (Obj_2a3130*)alloc(0x20);
        if (p)
            gObj_2a3130 = p->build();
        else
            gObj_2a3130 = 0;
        gObj_2a3130->init();
        gObj_2a3130->inner->f6(0x444d4853, 0);
        gObj_2a3130->inner->f6(0x54535441, 0);
        gObj_2a3130->inner->f6(0x444d4c42, 1);
    }
}