struct Lock_2751c0 {
    virtual void lock();
    virtual void unlock();
};
struct Drive {
    virtual void slot0();
    virtual void release();
    Lock_2751c0 lk;
    char pad[16];
    int refs;
};
struct Alloc_2751c0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};
extern char g_pool_2751c0;
extern Alloc_2751c0* g_frlloc_2751c0;
extern void* g_fr[];
extern void* g_rq[];
void __cdecl Lk(void*);
void __cdecl Ulk(void*);
class Obj_2751c0 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    Obj_2751c0* f0(unsigned char flags);
};
Obj_2751c0* Obj_2751c0::f0(unsigned char flags) {
    vptr = g_fr;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_rq;
    if (flags & 1) {
        Lk(&g_pool_2751c0);
        g_frlloc_2751c0->free(this);
        Ulk(&g_pool_2751c0);
    }
    return this;
}
