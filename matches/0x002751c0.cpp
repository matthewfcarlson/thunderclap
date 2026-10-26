#include "decls/data/engine/core.h"
// data: g_frlloc_2751c0 = DAT_0052a1e4, g_pool_2751c0 = DAT_0052a1c8

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
extern void* g_fr[];
extern void* g_rq[];
void __cdecl Lk(void*);
void __cdecl Ulk(void*);
class FileCommitRequest_2751c0 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    FileCommitRequest_2751c0* f0(unsigned char flags);
};
FileCommitRequest_2751c0* FileCommitRequest_2751c0::f0(unsigned char flags) {
    vptr = g_fr;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_rq;
    if (flags & 1) {
        Lk(((char*)&DAT_0052a1c8));
        (*(Alloc_2751c0**)&DAT_0052a1e4)->free(this);
        Ulk(((char*)&DAT_0052a1c8));
    }
    return this;
}
