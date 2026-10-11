// cl-flags: /O1
extern void* v[];
class Ref {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
void __stdcall Free(void*) throw();
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class O : public Base {
  public:
    char pad[0x7c];
    Ref* m80;
    char pad2[0x3c];
    void* mc0;
    void Stop(int) throw();
    void Flush(int) throw();
    void Sub() throw();
    ~O() throw();
};
O::~O() throw() {
    vptr = v;
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
