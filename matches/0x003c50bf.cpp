// cl-flags: /O1
extern void* v[];
extern void* bv[];
void __stdcall Fini(void*) throw();
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
    Ref* m10;
    int sub;
    ~O() throw();
};
O::~O() throw() {
    *(void* volatile*)&vptr = v;
    Fini(&sub);
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    if (m8) {
        m8->Release();
        m8 = 0;
    }
    vptr = bv;
}
