extern void* vD[];
extern void* vB[];
extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*) throw();
class D;
extern D* g_cur_327e20;
class D {
  public:
    void* vptr;
    D* vfunc_3(unsigned char f) throw();
    void Fini() throw();
};
D* D::vfunc_3(unsigned char f) throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if (g_cur_327e20 == this)
        g_cur_327e20 = 0;
    vptr = vB;
    Fini();
    if (f & 1)
        thunk_FUN_00267090(this);
    return this;
}
