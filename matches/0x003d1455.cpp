// cl-flags: /O1
extern void* v[];
extern void* bv[];
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
    char pad2[0x64];
    Ref* m70;
    void Sub() throw();
    ~O() throw();
};
O::~O() throw() {
    *(void* volatile*)&vptr = v;
    Sub();
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    if (m8) {
        m8->Release();
        m8 = 0;
    }
    vptr = bv;
}
