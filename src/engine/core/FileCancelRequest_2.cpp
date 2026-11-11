// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275570..0x00275600 (kind game, layer engine, confidence medium), dominant class core::FileCancelRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f5092546 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5092546 {} using namespace fn_f5092546;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f5092546 {
extern "C" char DAT_0042bb40[];
extern "C" int* FUN_002705f0();
class FileCancelRequest_275570 : public CoreRequest {
  public:
    CoreRequest* FUN_00274e60(hulk_uintptr);
    FileCancelRequest_275570* Init(void*);
};
struct Lock_275590 {
    virtual void lock();
    virtual void unlock();
};
struct Ref_275590 {
    virtual void v0();
    virtual void release();
};
struct Alloc_275590 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void free(void*);
};
class FileCancelRequest_275590 : public CoreRequest {
  public:
    FileCancelRequest_275590* f0(unsigned char flags);
};


// 0x00275570 FUN_00275570 (30 B): matches/0x00275570.cpp
// sym: ?Init@FileCancelRequest_275570@fn_f5092546@@QAEPAV12@PAX@Z
FileCancelRequest_275570* FileCancelRequest_275570::Init(void* file) {
    FUN_00274e60((hulk_uintptr)file);
    vftable = DAT_0042bb40;
    FUN_002705f0();
    return this;
}


// 0x00275590 core::FileCancelRequest::vfunc_0 (102 B): matches/0x00275590.cpp
// sym: ?f0@FileCancelRequest_275590@fn_f5092546@@QAEPAV12@E@Z
// data: the "FileRequest" pool = DAT_0052a1e4, its lock = DAT_0052a1c8
FileCancelRequest_275590* FileCancelRequest_275590::f0(unsigned char flags) {
    vftable = DAT_0042b99c;
    ((Lock_275590*)&((CoreFile*)file)->vftableMutable)->lock();
    --((CoreFile*)file)->field18;
    ((Lock_275590*)&((CoreFile*)file)->vftableMutable)->unlock();
    ((Ref_275590*)file)->release();
    vftable = DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Alloc_275590**)&DAT_0052a1e4)->free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f5092546
