class MemoryAllocatorMalloc {
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
    virtual int vfunc_9(int a, int b, int c, int d);
};
extern int helper(int, int, int, int);
int MemoryAllocatorMalloc::vfunc_9(int a, int b, int c, int d) {
    return helper(a, b, c, d);
}