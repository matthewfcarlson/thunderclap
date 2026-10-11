// cl-flags: /O1
extern void* v1[];
extern void* v2[];
class Ref {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
struct Pre {
    void* p0;
};
class Base {
  public:
    void* vptr;
    char pad[0x18];
    ~Base() throw();
};
class O : public Pre, public Base {
  public:
    Ref* m20;
    Ref* m24;
    ~O() throw();
};
O::~O() throw() {
    p0 = v1;
    vptr = v2;
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
}
