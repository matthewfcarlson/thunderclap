// cl-flags: /O1
extern void* v_3ce9a6[];
class Ref_3ce9a6 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
void __stdcall Free(void*) throw();
class Base_3ce9a6 {
  public:
    void* vptr;
    ~Base_3ce9a6() throw();
};
class O_3ce9a6 : public Base_3ce9a6 {
  public:
    char pad[0x7c];
    Ref_3ce9a6* m80;
    char pad2[0x3c];
    void* mc0;
    void Stop(int) throw();
    void Flush(int) throw();
    void Sub() throw();
    ~O_3ce9a6() throw();
};
O_3ce9a6::~O_3ce9a6() throw() {
    vptr = v_3ce9a6;
    for (unsigned i = 0; i < 6; i++)
        Stop(i);
    Flush(0);
    Sub();
    if (m80) {
        m80->Release();
        m80 = 0;
    }
    if (mc0) {
        Free(mc0);
        mc0 = 0;
    }
}
