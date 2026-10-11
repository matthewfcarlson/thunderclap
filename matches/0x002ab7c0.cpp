extern "C" void _ReadWriteBarrier();
void* operator new(unsigned int);
struct EB {
    virtual void f0();
    virtual void f1();
    EB() throw();
    int x;
};
struct Emitter : EB {
    Emitter() throw() {}
    virtual void f0();
};
struct LB {
    virtual void f0();
    virtual void f1();
    int a;
    int b;
    int c;
    int d;
    LB() throw() {
        a = 0;
        b = 0x15800;
        c = 0;
        d = 0;
    }
};
struct Loader : LB {
    Loader();
    virtual void f0();
    int m14;
    EB* m18;
};
Loader::Loader() {
    m14 = 0;
    m18 = 0;
    Emitter* t = new Emitter;
    _ReadWriteBarrier();
    EB* e = t;
    if (e)
        e->f0();
    if (m18)
        m18->f1();
    m18 = e;
}
