extern void* g_vftable[];
extern void* g_base_vftable[];
extern char g_lock[];
class Pool {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*);
};
extern Pool* g_pool;
void Lock(void*);
void Unlock(void*);
class B {
  public:
    virtual void v0();
    virtual void v1();
};
class Big {
  public:
    virtual void v0();
    virtual void v1();
    B sub;
    char pad[0xc];
    int cnt;
};
class Obj {
  public:
    void* vptr;
    char pad[4];
    Big* m8;
    Obj* f0(unsigned char flags);
};
Obj* Obj::f0(unsigned char flags) {
    Big* p = m8;
    vptr = g_vftable;
    p->sub.v0();
    m8->cnt--;
    m8->sub.v1();
    m8->v1();
    vptr = g_base_vftable;
    if (flags & 1) {
        Lock(g_lock);
        g_pool->Free(this);
        Unlock(g_lock);
    }
    return this;
}
