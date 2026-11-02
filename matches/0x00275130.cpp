#include "decls/data/engine/core.h"
// data: g_frlloc_275130 = DAT_0052a1e4, g_pool_275130 = DAT_0052a1c8

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
extern void* g_fr[];
extern void* g_rq[];
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
class FileCloseRequest_275130 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    FileCloseRequest_275130* f0(unsigned char flags);
};
FileCloseRequest_275130* FileCloseRequest_275130::f0(unsigned char flags) {
    vptr = g_fr;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_rq;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275130**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
