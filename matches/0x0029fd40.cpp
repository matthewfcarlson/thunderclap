extern "C" void _ReadWriteBarrier();
extern int vt1;
void operator delete(void*) throw();
void Free(void*) throw();
class Ref {
  public:
    virtual void f0() throw();
    virtual void Release() throw();
};
struct S {
    Ref* r;
    void* buf;
    ~S() throw() {
        r->Release();
        Free(buf);
    }
};
struct S2 {
    Ref* r0;
    Ref* r4;
    Ref* r8;
    Ref* rc;
    ~S2() throw() {
        rc->Release();
        r8->Release();
        r4->Release();
        r0->Release();
    }
};
class Root {
  public:
    void* vptr;
    ~Root() throw();
};
class D : public Root {
  public:
    void Fini() throw();
    char p[0x28];
    S* s2c;
    S* s30;
    S* s34;
    S* s38;
    S* s3c;
    S* s40;
    S2* s44;
    void* a48;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1;
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
