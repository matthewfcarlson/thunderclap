// cl-flags: /O1
extern void* v[];
class Ref {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class Base {
  public:
    void* vptr;
    char pad[0x18];
    ~Base() throw();
};
class O : public Base {
  public:
    Ref* m1c;
    Ref* m20;
    ~O() throw();
};
O::~O() throw() {
    void* p = m20;
    vptr = v;
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
}
