extern void* vP[];
extern void* vR[];
extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*) throw();
struct Elem {
    char pad[0xc0];
    void Fini() throw();
};
struct Ref {
    virtual void a() throw();
    virtual void release() throw();
};
class O {
  public:
    void* vptr;
    int pad;
    Ref* ref;
    Elem* arr;
    ~O() throw();
};
O::~O() throw() {
    Elem* a = arr;
    vptr = vP;
    if (a) {
        int n = ((int*)a)[-1];
        Elem* e = a + n;
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
