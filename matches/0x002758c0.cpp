struct Lock_2758c0 {
    virtual void lock();
    virtual void unlock();
};
struct Drive {
    virtual void slot0();
    virtual void release();
    Lock_2758c0 lk;
    char pad[12];
    int refs;
};
struct Alloc_2758c0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};
extern char g_pool_2758c0;
extern Alloc_2758c0* g_alloc;
extern void* g_a_2758c0[];
extern void* g_b_2758c0[];
void __cdecl Lk(void*);
void __cdecl Ulk(void*);
class Obj_2758c0 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    Obj_2758c0* f0(unsigned char flags);
};
Obj_2758c0* Obj_2758c0::f0(unsigned char flags) {
    vptr = g_a_2758c0;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_b_2758c0;
    if (flags & 1) {
        Lk(&g_pool_2758c0);
        g_alloc->free(this);
        Ulk(&g_pool_2758c0);
    }
    return this;
}
