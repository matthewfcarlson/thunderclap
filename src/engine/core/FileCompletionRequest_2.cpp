// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274ca0..0x00274d80 (kind game, layer engine, confidence medium), dominant class core::FileCompletionRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_ffdeb1ec {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffdeb1ec {} using namespace fn_ffdeb1ec;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ffdeb1ec {
extern "C" char DAT_0042b954[];
extern "C" int* FUN_002705f0();
class Intf {
  public:
    virtual void f0();
    virtual void f1();
};
class Ref_274ca0 {
  public:
    virtual void v0();
};
class FileCompletionRequest_274ca0 : public CoreCompletionRequest {
  public:
    FileCompletionRequest_274ca0* Init(void* x, void* y, void* z, unsigned int w);
};
struct Obj_274d20 {
    virtual void f0();
    virtual void f1();
};
struct GlobalObj_274d20 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
struct FileCompletionRequest_274d20 : CoreCompletionRequest {
    FileCompletionRequest_274d20* vfunc_0(unsigned char);
};


// 0x00274ca0 FUN_00274ca0 (119 B): matches/0x00274ca0.cpp
// sym: ?Init@FileCompletionRequest_274ca0@fn_ffdeb1ec@@QAEPAV12@PAX00I@Z
FileCompletionRequest_274ca0* FileCompletionRequest_274ca0::Init(void* x, void* y, void* z, unsigned int w) {
    vftable = DAT_0042b914;
    next = 0;
    FUN_002705f0();
    vftable = DAT_0042b9dc;
    thread = x;
    FUN_002705f0();
    vftable = DAT_0042b954;
    file = y;
    callback = z;
    context = w;
    FUN_002705f0();
    ((Ref_274ca0*)callback)->v0();
    ((Intf*)&((CoreFile*)file)->vftableMutable)->f0();
    ((CoreFile*)file)->field18++;
    ((Intf*)&((CoreFile*)file)->vftableMutable)->f1();
    ((Ref_274ca0*)file)->v0();
    return this;
}


// 0x00274d20 core::FileCompletionRequest::vfunc_0 (82 B): matches/0x00274d20.cpp
// sym: ?vfunc_0@FileCompletionRequest_274d20@fn_ffdeb1ec@@QAEPAU12@E@Z
// data: gLock_274d20 = DAT_0052a1c8, gObject_274d20 = DAT_0052a1e4
FileCompletionRequest_274d20* FileCompletionRequest_274d20::vfunc_0(unsigned char param) {
    vftable = DAT_0042b954;
    ((Obj_274d20*)callback)->f1();
    ((Obj_274d20*)file)->f1();
    vftable = DAT_0042b914;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(GlobalObj_274d20**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_ffdeb1ec
