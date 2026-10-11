struct Lock {
    virtual void lock();
    virtual void unlock();
};
struct Drive {
    virtual void slot0();
    virtual void release();
    Lock lk;
    char pad[12];
    int refs;
};
struct Alloc {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};
extern char g_pool;
extern Alloc* g_alloc;
extern void* g_a[];
extern void* g_b[];
void __cdecl Lk(void*);
void __cdecl Ulk(void*);
class Obj {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    Obj* f0(unsigned char flags);
};
Obj* Obj::f0(unsigned char flags) {
    vptr = g_a;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_b;
    if (flags & 1) {
        Lk(&g_pool);
        g_alloc->free(this);
        Ulk(&g_pool);
    }
    return this;
}
