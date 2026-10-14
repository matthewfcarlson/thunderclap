namespace pure3d {
struct Block_3212d0 {
    unsigned int v[16];
};
class d3dContext {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual Block_3212d0* f20();
    char pad[0x414 - 4];
    void vfunc_110(int n, char b);
};
void d3dContext::vfunc_110(int n, char b) {
    char* p = (char*)this;
    p[0x414] = 1;
    p[n + 0x40c] = 1;
    if (b) {
        Block_3212d0* s = f20();
        Block_3212d0* d = (Block_3212d0*)(p + n * 0x40 + 0x20c);
        *d = *s;
    }
}
} // namespace pure3d
