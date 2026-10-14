extern int vt1_297350, vt2;
extern void Free(void*);
class Ref_297350 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_297350 {
  public:
    void* vptr;
    ~Root_297350() throw();
};
class D : public Root_297350 {
  public:
    char p[0x14];
    unsigned n;
    Ref_297350** arr;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_297350;
    for (unsigned i = 0; i < n; i++) {
        Ref_297350** pp = &arr[i];
        Ref_297350* r = *pp;
        if (r) {
            r->Release();
            *pp = 0;
        }
    }
    if (arr)
        Free(arr);
    vptr = &vt2;
}
