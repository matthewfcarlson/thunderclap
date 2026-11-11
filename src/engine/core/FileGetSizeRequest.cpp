// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002754d0..0x00275570 (kind game, layer engine, confidence medium), dominant class core::FileGetSizeRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f5223212 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5223212 {} using namespace fn_f5223212;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f5223212 {
extern "C" char DAT_0042bb20[];
extern "C" int* FUN_002705f0();
class FileGetSizeRequest_2754d0 : public CoreRequest {
  public:
    unsigned int* result;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileGetSizeRequest_2754d0* Init(void*, unsigned int*);
};
struct Lock_275500 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_275500 {
    virtual void v0();
    virtual void release();
};
struct Alloc_275500 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileGetSizeRequest_275500 : public CoreRequest {
  public:
    FileGetSizeRequest_275500* f0(unsigned char flags);
};


// 0x002754d0 FUN_002754d0 (37 B): matches/0x002754d0.cpp
// sym: ?Init@FileGetSizeRequest_2754d0@fn_f5223212@@QAEPAV12@PAXPAI@Z
FileGetSizeRequest_2754d0* FileGetSizeRequest_2754d0::Init(void* file, unsigned int* result_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bb20;
    result = result_;
    FUN_002705f0();
    return this;
}


// 0x00275500 core::FileGetSizeRequest::vfunc_0 (102 B): matches/0x00275500.cpp
// sym: ?f0@FileGetSizeRequest_275500@fn_f5223212@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileGetSizeRequest_275500* FileGetSizeRequest_275500::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_275500*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_275500*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_275500*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275500**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f5223212
