// cl-flags: /O1
extern void* v_3d1455[];
extern void* bv[];
class Ref_3d1455 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class O_3d1455 {
  public:
    void* vptr;
    int pad;
    Ref_3d1455* m8;
    char pad2[0x64];
    Ref_3d1455* m70;
    void Sub() throw();
    ~O_3d1455() throw();
};
O_3d1455::~O_3d1455() throw() {
    *(void* volatile*)&vptr = v_3d1455;
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
