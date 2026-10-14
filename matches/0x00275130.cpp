struct Lock_275130 {
    virtual void lock();
    virtual void unlock();
};
struct Drive {
    virtual void slot0();
    virtual void release();
    Lock_275130 lk;
    char pad[16];
    int refs;
};
struct Alloc_275130 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};
extern char g_pool_275130;
extern Alloc_275130* g_frlloc_275130;
extern void* g_fr[];
extern void* g_rq[];
void __cdecl Lk(void*);
void __cdecl Ulk(void*);
class Obj_275130 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    Obj_275130* f0(unsigned char flags);
};
Obj_275130* Obj_275130::f0(unsigned char flags) {
    vptr = g_fr;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_rq;
    if (flags & 1) {
        Lk(&g_pool_275130);
        g_frlloc_275130->free(this);
        Ulk(&g_pool_275130);
    }
    return this;
}
