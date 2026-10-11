extern "C" void _ReadWriteBarrier();
extern int vt1;
extern void Free(void*);
class Root {
  public:
    void* vptr;
    ~Root() throw();
};
class D : public Root {
  public:
    char p[0x3c];
    int a40;
    int a44;
    char q[8];
    void* a50;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    a40 = 0;
    _ReadWriteBarrier();
    if (a50)
        Free(a50);
    if (a44)
        Free((void*)a44);
}
