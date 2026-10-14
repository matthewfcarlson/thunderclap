// cl-flags: /O1
extern void* v1_3c599e[];
extern void* v2_3c599e[];
class Ref_3c599e {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
struct Pre {
    void* p0;
};
class Base_3c599e {
  public:
    void* vptr;
    char pad[0x18];
    ~Base_3c599e() throw();
};
class O_3c599e : public Pre, public Base_3c599e {
  public:
    Ref_3c599e* m20;
    Ref_3c599e* m24;
    ~O_3c599e() throw();
};
O_3c599e::~O_3c599e() throw() {
    p0 = v1_3c599e;
    vptr = v2_3c599e;
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
}
