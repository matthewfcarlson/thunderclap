// cl-flags: /O1
extern void* v_3c4a8f[];
extern void* bv[];
extern int g_3c4a8f;
class Ref_3c4a8f {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class O_3c4a8f {
  public:
    void* vptr;
    int pad;
    Ref_3c4a8f* m8;
    Ref_3c4a8f* mc;
    ~O_3c4a8f() throw();
};
O_3c4a8f::~O_3c4a8f() throw() {
    *(void* volatile*)&vptr = v_3c4a8f;
    g_3c4a8f = 0;
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
