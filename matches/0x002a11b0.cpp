extern "C" void _ReadWriteBarrier();
extern int vt1;
extern void Free(void*);
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class Root {
  public:
    void* vptr;
    ~Root() throw();
};
class D : public Root {
  public:
    char p[0xc];
    int n;
    int cap;
    Ref** arr;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    for (int i = 0; i < n; i++) {
        Ref* r = arr[i];
        if (r)
            r->Release();
    }
    n = 0;
    cap = 0;
    _ReadWriteBarrier();
    if (arr)
        Free(arr);
}
