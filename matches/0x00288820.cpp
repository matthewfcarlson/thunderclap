extern void* __cdecl FUN_0008d6d0(unsigned int);
struct B {
    int a;
    B() { a = 0; }
};
class AMB : public B {
  public:
    virtual void f0();
    unsigned int sz1;
    unsigned int sz2;
    int b;
    int c;
    void* buf1;
    void* buf2;
    AMB(unsigned int s1, unsigned int s2);
};
AMB::AMB(unsigned int s1, unsigned int s2) {
    sz1 = s1;
    b = 0;
    buf1 = s1 > 0 ? FUN_0008d6d0(s1) : 0;
    sz2 = s2;
    c = 0;
    buf2 = s2 > 0 ? FUN_0008d6d0(s2) : 0;
}
