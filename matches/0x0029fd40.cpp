extern "C" void _ReadWriteBarrier();
extern int vt1_29fd40;
void operator delete(void*) throw();
void Free(void*) throw();
class Ref_29fd40 {
  public:
    virtual void f0() throw();
    virtual void Release() throw();
};
struct S_29fd40 {
    Ref_29fd40* r;
    void* buf;
    ~S_29fd40() throw() {
        r->Release();
        Free(buf);
    }
};
struct S2_29fd40 {
    Ref_29fd40* r0;
    Ref_29fd40* r4;
    Ref_29fd40* r8;
    Ref_29fd40* rc;
    ~S2_29fd40() throw() {
        rc->Release();
        r8->Release();
        r4->Release();
        r0->Release();
    }
};
class Root_29fd40 {
  public:
    void* vptr;
    ~Root_29fd40() throw();
};
class D : public Root_29fd40 {
  public:
    void Fini() throw();
    char p[0x28];
    S_29fd40* s2c;
    S_29fd40* s30;
    S_29fd40* s34;
    S_29fd40* s38;
    S_29fd40* s3c;
    S_29fd40* s40;
    S2_29fd40* s44;
    void* a48;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_29fd40;
    Fini();
    if (s2c)
        delete s2c;
    if (s30)
        delete s30;
    if (s34)
        delete s34;
    if (s38)
        delete s38;
    if (s3c)
        delete s3c;
    if (s40)
        delete s40;
    if (s44)
        delete s44;
    operator delete(a48);
}
