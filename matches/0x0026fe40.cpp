class MemoryPool {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void vfunc_14(int*, int*, int*);
    char pad[0x18];
    int x;
    int y;
    char pad24[4];
    int z;
    char pad2c[4];
    MemoryPool* pool;
};
void MemoryPool::vfunc_14(int* p, int* q, int* r) {
    if (p)
        *p = 0;
    if (q)
        *q = 0;
    if (r)
        *r = 0;
    if (pool)
        pool->vfunc_14(p, q, r);
    if (p)
        *p += x;
    if (q)
        *q += y - z;
    if (r)
        *r += z;
}