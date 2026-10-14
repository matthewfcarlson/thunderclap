extern void* g_vftable_275780[];
extern void* g_base_vftable[];
extern char g_lock_275780[];
class Pool_275780 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*);
};
extern Pool_275780* g_pool_275780;
void Lock(void*);
void Unlock(void*);
class B_275780 {
  public:
    virtual void v0();
    virtual void v1();
};
class Big_275780 {
  public:
    virtual void v0();
    virtual void v1();
    B_275780 sub;
    char pad[0xc];
    int cnt;
};
class Obj_275780 {
  public:
    void* vptr;
    char pad[4];
    Big_275780* m8;
    Obj_275780* f0(unsigned char flags);
};
Obj_275780* Obj_275780::f0(unsigned char flags) {
    Big_275780* p = m8;
    vptr = g_vftable_275780;
    p->sub.v0();
    m8->cnt--;
    m8->sub.v1();
    m8->v1();
    vptr = g_base_vftable;
    if (flags & 1) {
        Lock(g_lock_275780);
        g_pool_275780->Free(this);
        Unlock(g_lock_275780);
    }
    return this;
}
