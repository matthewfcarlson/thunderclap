// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275880..0x00275930 (kind game, layer engine, confidence medium), dominant class core::DriveCreateDirectoryRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f16f06b3 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f16f06b3 {} using namespace fn_f16f06b3;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f16f06b3 {
extern "C" char DAT_0042bbc0[];
typedef unsigned int u32_275880;
struct ThisCall_00275600 {
    void FUN_00275600(int);
};
extern void FUN_002705f0();
extern char* _strncpy(char*, const char*, unsigned int);
class DriveCreateDirectoryRequest {
  public:
    void* vptr;
    char pad4[8];
    char path[16];
    DriveCreateDirectoryRequest* Create(int a, char* p);
};
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
class DriveCreateDirectoryRequest_2758c0 {
  public:
    void* vptr;
    int pad;
    Drive* drive;
    DriveCreateDirectoryRequest_2758c0* f0(unsigned char flags);
};


// 0x00275880 FUN_00275880 (53 B): matches/0x00275880.cpp
// sym: ?Create@DriveCreateDirectoryRequest@fn_f16f06b3@@QAEPAV12@HPAD@Z
DriveCreateDirectoryRequest* DriveCreateDirectoryRequest::Create(int a, char* p) {
    ((ThisCall_00275600*)(this))->FUN_00275600(a);
    vptr = (void*)((hulk_intptr)DAT_0042bbc0);
    FUN_002705f0();
    _strncpy(path, p, 0x10);
    path[16] = 0;
    return this;
}


// 0x002758c0 core::DriveCreateDirectoryRequest::vfunc_0 (102 B): matches/0x002758c0.cpp
// sym: ?f0@DriveCreateDirectoryRequest_2758c0@fn_f16f06b3@@QAEPAV12@E@Z
// data: g_alloc = DAT_0052a1e4, g_pool_2758c0 = DAT_0052a1c8
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

} // namespace fn_f16f06b3
