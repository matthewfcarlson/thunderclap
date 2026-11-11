// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002751c0..0x00275230 (kind game, layer engine, confidence medium), dominant class core::FileCommitRequest
#include "tree_prelude.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_ff004081 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff004081 {} using namespace fn_ff004081;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ff004081 {
struct Lock_2751c0 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_2751c0 {
    virtual void v0();
    virtual void release();
};
struct Alloc_2751c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileCommitRequest_2751c0 : public CoreRequest {
  public:
    FileCommitRequest_2751c0* f0(unsigned char flags);
};


// 0x002751c0 core::FileCommitRequest::vfunc_0 (102 B): matches/0x002751c0.cpp
// sym: ?f0@FileCommitRequest_2751c0@fn_ff004081@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileCommitRequest_2751c0* FileCommitRequest_2751c0::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_2751c0*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_2751c0*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_2751c0*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_2751c0**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_ff004081
