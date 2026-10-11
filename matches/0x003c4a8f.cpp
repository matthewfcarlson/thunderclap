// cl-flags: /O1
extern void* v[];
extern void* bv[];
extern int g;
class Ref {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class O {
  public:
    void* vptr;
    int pad;
    Ref* m8;
    Ref* mc;
    ~O() throw();
};
O::~O() throw() {
    *(void* volatile*)&vptr = v;
    g = 0;
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m8) {
        m8->Release();
        m8 = 0;
    }
    vptr = bv;
}
