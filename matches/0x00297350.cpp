extern int vt1, vt2;
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
    char p[0x14];
    unsigned n;
    Ref** arr;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
    for (unsigned i = 0; i < n; i++) {
        Ref** pp = &arr[i];
        Ref* r = *pp;
        if (r) {
            r->Release();
            *pp = 0;
        }
    }
    if (arr)
        Free(arr);
    vptr = &vt2;
}
