// cl-flags: /O1
extern void* g_a_3d237c[];
class Ref_3d237c {
  public:
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
class Base_3d237c {
  public:
    void* vptr;
    ~Base_3d237c() throw();
};
class A_3d237c : public Base_3d237c {
  public:
    char pad[0x80 - 4];
    Ref_3d237c* m80;
    void Sub(int i) throw();
    void Sub0() throw();
    ~A_3d237c() throw();
};
A_3d237c::~A_3d237c() throw() {
    vptr = g_a_3d237c;
    Sub0();
    for (unsigned i = 0; i < 6; i++)
        Sub(i);
    if (m80) {
        m80->Release();
        m80 = 0;
    }
}
