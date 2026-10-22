extern void* vD[];
extern void* vB[];
extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*) throw();
struct Ref_2e1530 {
    virtual void a() throw();
    virtual void release() throw();
};
class PrimGroupStreamed_2e1530 {
  public:
    void* vptr;
    char pad[0x3c];
    Ref_2e1530* r40;
    char pad2[0x5c - 0x44];
    Ref_2e1530* r5c;
    PrimGroupStreamed_2e1530* vfunc_2(unsigned char f) throw();
    void Fini() throw();
};
PrimGroupStreamed_2e1530* PrimGroupStreamed_2e1530::vfunc_2(unsigned char f) throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if (r5c) {
        r5c->release();
        r5c = 0;
    }
    vptr = vB;
    _ReadWriteBarrier();
    if (r40) {
        r40->release();
        r40 = 0;
    }
    Fini();
    if (f & 1)
        thunk_FUN_00267090(this);
    return this;
}
