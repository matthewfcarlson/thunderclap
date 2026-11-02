#include "decls/data/engine/core.h"
// data: g_alloc = DAT_0052a1e4, g_pool_2758c0 = DAT_0052a1c8

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
extern void* g_a_2758c0[];
extern void* g_b_2758c0[];
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
class DriveCreateDirectoryRequest_2758c0 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    DriveCreateDirectoryRequest_2758c0* f0(unsigned char flags);
};
DriveCreateDirectoryRequest_2758c0* DriveCreateDirectoryRequest_2758c0::f0(unsigned char flags) {
    vptr = g_a_2758c0;
    drive->lk.lock();
    --drive->refs;
    drive->lk.unlock();
    drive->release();
    vptr = g_b_2758c0;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_2758c0**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}
