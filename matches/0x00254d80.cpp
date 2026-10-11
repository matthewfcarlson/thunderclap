extern "C" void _ReadWriteBarrier();
inline void* operator new(unsigned int, void* p) {
    return p;
}
extern char gPool[];
void* __cdecl PoolAlloc(void*);
struct Base {
    virtual void f0();
    Base() throw();
    int b4;
};
struct Init {
    int m8, mc, m10, m14, m18;
    Init() throw() {
        m8 = 0;
        mc = 0;
        m10 = 0;
        _ReadWriteBarrier();
        m14 = 1;
        m18 = 1;
    }
};
struct Repeat : Base, Init {
    Repeat() throw() {}
    virtual void f0();
};
struct Type {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Base* vfunc_3();
};
Base* Type::vfunc_3() {
    Repeat* r = (Repeat*)PoolAlloc(gPool);
    if (r)
        return new (r) Repeat;
    return 0;
}
