// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275880..0x00275930 (kind game, layer engine, confidence medium), dominant class core::DriveCreateDirectoryRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/instance_drive.h"
#define TREE_TU_BEGIN namespace fn_f16f06b3 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f16f06b3 {} using namespace fn_f16f06b3;
#include "engine/core.h"
// (ren2) strncpy's own name (CRT, C linkage)
#if !defined(HULK_COMPAT_CRT)
extern "C" char* __cdecl strncpy(char*, const char*, size_t);
#endif

// ---- declarations shared by the functions below
namespace fn_f16f06b3 {
extern "C" char DAT_0042bbc0[];
typedef unsigned int u32_275880;
// (x64t10) DriveRequest's constructor takes the InstanceDrive (decls/instance_drive.h; was an int)
struct ThisCall_00275600 {
    void FUN_00275600(HulkInstanceDrive*);
};
extern void FUN_002705f0();
class DriveCreateDirectoryRequest {
  public:
    void* vptr;
    char pad4[8];
    char path[16];
    DriveCreateDirectoryRequest* Create(HulkInstanceDrive* a, char* p);
};
struct Lock_2758c0 {
    virtual void lock();
    virtual void unlock();
};
struct Drive {
    virtual void slot0();
    virtual void release();
};
struct Alloc_2758c0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void free(void*);
};
extern void* hulk_at_0042b9bc[];
extern void* hulk_at_0042b914[];
class DriveCreateDirectoryRequest_2758c0 {
  public:
    void* vptr;
    int pad;
    HulkInstanceDrive* drive;   // (x64t10) decls/instance_drive.h
    DriveCreateDirectoryRequest_2758c0* f0(unsigned char flags);
};


// 0x00275880 FUN_00275880 (53 B): matches/0x00275880.cpp
// sym: ?Create@DriveCreateDirectoryRequest@fn_f16f06b3@@QAEPAV12@PAUHulkInstanceDrive@@PAD@Z
DriveCreateDirectoryRequest* DriveCreateDirectoryRequest::Create(HulkInstanceDrive* a, char* p) {
    ((ThisCall_00275600*)(this))->FUN_00275600(a);
    vptr = (void*)((hulk_intptr)DAT_0042bbc0);
    FUN_002705f0();
    strncpy(path, p, 0x10);
    path[16] = 0;
    return this;
}


// 0x002758c0 core::DriveCreateDirectoryRequest::vfunc_0 (102 B): matches/0x002758c0.cpp
// sym: ?f0@DriveCreateDirectoryRequest_2758c0@fn_f16f06b3@@QAEPAV12@E@Z
// data: g_alloc = DAT_0052a1e4, g_pool_2758c0 = DAT_0052a1c8
DriveCreateDirectoryRequest_2758c0* DriveCreateDirectoryRequest_2758c0::f0(unsigned char flags) {
    vptr = hulk_at_0042b9bc;
    ((Lock_2758c0*)&drive->mutableVftable)->lock();
    --drive->pending;
    ((Lock_2758c0*)&drive->mutableVftable)->unlock();
    ((Drive*)drive)->release();
    vptr = hulk_at_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_2758c0**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f16f06b3
