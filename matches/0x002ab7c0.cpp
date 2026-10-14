extern "C" void _ReadWriteBarrier();
void* operator new(unsigned int);
struct EB {
    virtual void f0();
    virtual void f1();
    EB() throw();
    int x;
};
struct Emitter_2ab7c0 : EB {
    Emitter_2ab7c0() throw() {}
    virtual void f0();
};
struct LB_2ab7c0 {
    virtual void f0();
    virtual void f1();
    int a;
    int b;
    int c;
    int d;
    LB_2ab7c0() throw() {
        a = 0;
        b = 0x15800;
        c = 0;
        d = 0;
    }
};
struct Loader_2ab7c0 : LB_2ab7c0 {
    Loader_2ab7c0();
    virtual void f0();
    int m14;
    EB* m18;
};
Loader_2ab7c0::Loader_2ab7c0() {
    m14 = 0;
    m18 = 0;
    Emitter_2ab7c0* t = new Emitter_2ab7c0;
    _ReadWriteBarrier();
    EB* e = t;
    if (e)
        e->f0();
    if (m18)
        m18->f1();
    m18 = e;
}
