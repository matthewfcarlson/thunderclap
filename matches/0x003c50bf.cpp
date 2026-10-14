// cl-flags: /O1
extern void* v_3c50bf[];
extern void* bv[];
void __stdcall Fini(void*) throw();
class Ref_3c50bf {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class O_3c50bf {
  public:
    void* vptr;
    int pad;
    Ref_3c50bf* m8;
    Ref_3c50bf* mc;
    Ref_3c50bf* m10;
    int sub;
    ~O_3c50bf() throw();
};
O_3c50bf::~O_3c50bf() throw() {
    *(void* volatile*)&vptr = v_3c50bf;
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
