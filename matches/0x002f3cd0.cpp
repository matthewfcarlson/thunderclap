extern void* vD[];
extern void* vB[];
extern "C" void _ReadWriteBarrier();
struct Ref {
    virtual void a() throw();
    virtual void release() throw();
};
class D {
  public:
    void* vptr;
    char pad[0x40];
    Ref* ref;
    void Fini() throw();
    void dtor() throw();
};
void D::dtor() throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if (ref) {
        ref->release();
        ref = 0;
    }
    vptr = vB;
    Fini();
}
