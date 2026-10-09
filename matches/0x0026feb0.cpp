class MemPoolParent {
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
    virtual char Stats(int* a, int* b, int* c, int* d);
};

class MemoryPool {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual char vfunc_9(int* a, int* b, int* c, int* d);
    char pad[0x1c - 4];
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    MemPoolParent* parent;
};

char MemoryPool::vfunc_9(int* a, int* b, int* c, int* d) {
    if (a)
        *a = 0;
    if (b)
        *b = 0;
    if (c)
        *c = 0;
    if (d)
        *d = 0;
    if (parent)
        parent->Stats(a, b, c, d);
    if (a)
        *a += (m20 - m28) * m1c;
    if (b)
        *b += m1c;
    if (c)
        *c += m28;
    if (d)
        *d += m2c * m1c;
    return 1;
}
