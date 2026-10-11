// cl-flags: /O1
extern void* g_a[];
class Ref {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class A : public Base {
  public:
    char pad[0x80 - 4];
    Ref* m80;
    void Sub(int i) throw();
    void Sub0() throw();
    ~A() throw();
};
A::~A() throw() {
    vptr = g_a;
    Sub0();
    for (unsigned i = 0; i < 6; i++)
        Sub(i);
    if (m80) {
        m80->Release();
        m80 = 0;
    }
}
