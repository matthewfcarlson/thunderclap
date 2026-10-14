extern void* g_vftable_275810[];
extern void* g_base_vftable[];
extern char g_lock_275810[];
class Pool_275810 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*);
};
extern Pool_275810* g_pool_275810;
void Lock(void*);
void Unlock(void*);
class B_275810 {
  public:
    virtual void v0();
    virtual void v1();
};
class Big_275810 {
  public:
    virtual void v0();
    virtual void v1();
    B_275810 sub;
    char pad[0xc];
    int cnt;
};
class Obj_275810 {
  public:
    void* vptr;
    char pad[4];
    Big_275810* m8;
    Obj_275810* f0(unsigned char flags);
};
Obj_275810* Obj_275810::f0(unsigned char flags) {
    Big_275810* p = m8;
    vptr = g_vftable_275810;
    p->sub.v0();
    m8->cnt--;
    m8->sub.v1();
    m8->v1();
    vptr = g_base_vftable;
    if (flags & 1) {
        Lock(g_lock_275810);
        g_pool_275810->Free(this);
        Unlock(g_lock_275810);
    }
    return this;
}
