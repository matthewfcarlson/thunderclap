// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275430..0x002754d0 (kind game, layer engine, confidence medium), dominant class core::FileGetPositionRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_fc531f01 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc531f01 {} using namespace fn_fc531f01;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fc531f01 {
extern "C" char DAT_0042bb00[];
extern "C" int* FUN_002705f0();
class FileGetPositionRequest_275430 : public CoreRequest {
  public:
    unsigned int* result;
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileGetPositionRequest_275430* Init(void*, unsigned int*);
};
struct Lock_275460 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_275460 {
    virtual void v0();
    virtual void release();
};
struct Alloc_275460 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileGetPositionRequest_275460 : public CoreRequest {
  public:
    FileGetPositionRequest_275460* f0(unsigned char flags);
};


// 0x00275430 FUN_00275430 (37 B): matches/0x00275430.cpp
// sym: ?Init@FileGetPositionRequest_275430@fn_fc531f01@@QAEPAV12@PAXPAI@Z
FileGetPositionRequest_275430* FileGetPositionRequest_275430::Init(void* file, unsigned int* result_) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bb00;
    result = result_;
    FUN_002705f0();
    return this;
}


// 0x00275460 core::FileGetPositionRequest::vfunc_0 (102 B): matches/0x00275460.cpp
// sym: ?f0@FileGetPositionRequest_275460@fn_fc531f01@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileGetPositionRequest_275460* FileGetPositionRequest_275460::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_275460*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_275460*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_275460*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275460**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_fc531f01
