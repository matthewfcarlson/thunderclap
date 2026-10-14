struct Lock_275270 {
    virtual void lock();
    virtual void unlock();
};
struct Drive {
    virtual void slot0();
    virtual void release();
    Lock_275270 lk;
    char pad[16];
    int refs;
};
struct Alloc_275270 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};
extern char g_pool_275270;
extern Alloc_275270* g_frlloc_275270;
extern void* g_fr[];
extern void* g_rq[];
void __cdecl Lk(void*);
void __cdecl Ulk(void*);
class Obj_275270 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    Obj_275270* f0(unsigned char flags);
};
Obj_275270* Obj_275270::f0(unsigned char flags) {
    vptr = g_fr;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_rq;
    if (flags & 1) {
        Lk(&g_pool_275270);
        g_frlloc_275270->free(this);
        Ulk(&g_pool_275270);
    }
    return this;
}
