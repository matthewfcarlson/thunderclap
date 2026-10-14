extern void* vP[];
extern void* vR[];
extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*) throw();
struct Elem_30f810 {
    char pad[0xc0];
    void Fini() throw();
};
struct Ref_30f810 {
    virtual void a() throw();
    virtual void release() throw();
};
class O_30f810 {
  public:
    void* vptr;
    int pad;
    Ref_30f810* ref;
    Elem_30f810* arr;
    ~O_30f810() throw();
};
O_30f810::~O_30f810() throw() {
    Elem_30f810* a = arr;
    vptr = vP;
    if (a) {
        int n = ((int*)a)[-1];
        Elem_30f810* e = a + n;
        while (--n >= 0) {
            e--;
            e->Fini();
        }
        thunk_FUN_00267090((int*)a - 1);
    }
    if (ref)
        ref->release();
    vptr = vR;
}
