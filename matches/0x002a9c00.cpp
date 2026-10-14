class Obj_2a9c00 {
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
    char pad[0x40 - sizeof(void*)];
    Obj_2a9c00* link;
    void initialize(Obj_2a9c00*);
    Obj_2a9c00* vfunc_4();
};
extern "C" int BQVtable;
extern "C" void* __cdecl alloc(unsigned int);
Obj_2a9c00* Obj_2a9c00::vfunc_4() {
    Obj_2a9c00* p = (Obj_2a9c00*)alloc(0x48);
    if (p) {
        p->initialize(this);
        *(int*)p = (int)&BQVtable;
        int* z = (int*)((char*)p + 0x40);
        *z = 0;
        Obj_2a9c00* q = link;
        if (q)
            q->f0();
        Obj_2a9c00* old = p->link;
        if (old)
            old->f1();
        p->link = q;
        return p;
    }
    return 0;
}