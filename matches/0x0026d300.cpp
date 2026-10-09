// Same code shape as 0x0026d2e0 (propagated; names are from that function)
class MemoryTwoWayAllocator {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int vfunc_5(unsigned int);
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
    char pad[0x10 - 4];
    unsigned int a;
    unsigned int b;
};
int MemoryTwoWayAllocator::vfunc_5(unsigned int x) {
    if (x >= a && x < b)
        return 1;
    return 0;
}