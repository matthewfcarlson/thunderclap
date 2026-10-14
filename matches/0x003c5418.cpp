// cl-flags: /O1
extern void* v_3c5418[];
class Ref_3c5418 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class Base_3c5418 {
  public:
    void* vptr;
    char pad[0x18];
    ~Base_3c5418() throw();
};
class O_3c5418 : public Base_3c5418 {
  public:
    Ref_3c5418* m1c;
    Ref_3c5418* m20;
    ~O_3c5418() throw();
};
O_3c5418::~O_3c5418() throw() {
    void* p = m20;
    vptr = v_3c5418;
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
}
