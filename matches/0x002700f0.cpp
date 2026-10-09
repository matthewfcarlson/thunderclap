class MemoryPool {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(unsigned int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad14[20];
    unsigned int start;
    int stride;
    int count;
    char pad24[12];
    MemoryPool* fallback;
};
bool MemoryPool::vfunc_5(unsigned int p) {
    unsigned int s = start;
    if (p >= s && p < count * stride + s)
        return true;
    if (fallback)
        return fallback->vfunc_5(p);
    return false;
}