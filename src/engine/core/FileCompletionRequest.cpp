// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002736b0..0x00273750 (kind game, layer engine, confidence high), dominant class core::FileCompletionRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f41cf0f7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f41cf0f7 {} using namespace fn_f41cf0f7;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f41cf0f7 {
class Obj_2736b0 {
  public:
    virtual void f();
    virtual void g();
};
class FileCompletionRequest {
  public:
    void** vt;
    char pad[8];
    Obj_2736b0* m0c;
    Obj_2736b0* m10;
    void Finish();
};
struct Drive_2736e0 {
    void FUN_002728e0(void* request);
};
struct FileCompletionRequest_2736e0 : CoreCompletionRequest {
    int vfunc_1();
};
struct I0 {
    virtual void f();
    virtual void g();
};
struct I3 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(unsigned int);
};
struct FileCompletionRequest_273700 : CoreCompletionRequest {
    void vfunc_7();
};


// 0x002736b0 FUN_002736b0 (33 B): matches/0x002736b0.cpp
// sym: ?Finish@FileCompletionRequest@fn_f41cf0f7@@QAEXXZ
void FileCompletionRequest::Finish() {
    vt = &vFileCompletion;
    m10->g();
    m0c->g();
    vt = &vRequest;
}


// 0x002736e0 core::FileCompletionRequest::vfunc_1 (18 B): matches/0x002736e0.cpp
// sym: ?vfunc_1@FileCompletionRequest_2736e0@fn_f41cf0f7@@QAEHXZ
// the drive's pending list (0x002728e0 appends)
int FileCompletionRequest_2736e0::vfunc_1() {
    ((Drive_2736e0*)((CoreFile*)file)->provider)->FUN_002728e0(this);
    return 3;
}


// 0x00273700 core::FileCompletionRequest::vfunc_7 (45 B): matches/0x00273700.cpp
// sym: ?vfunc_7@FileCompletionRequest_273700@fn_f41cf0f7@@QAEXXZ
void FileCompletionRequest_273700::vfunc_7() {
    ((I0*)&((CoreFile*)file)->vftableMutable)->f();
    --((CoreFile*)file)->field18;
    ((I0*)&((CoreFile*)file)->vftableMutable)->g();
    ((I3*)callback)->d(context);
}

} // namespace fn_f41cf0f7

// 0x00273730 core::FileCompletionRequest::vfunc_3 (7 B): matches/0x00273730.cpp
// sym: ?vfunc_3@FileCompletionRequest@core@@UAEHXZ
// the request's drive: its file's (records.h CoreCompletionRequest, CoreFile provider)
hulk_intptr core::FileCompletionRequest::vfunc_3() {
    return (hulk_intptr)((CoreFile*)((CoreCompletionRequest*)this)->file)->provider;
}


// 0x00273740 core::FileCompletionRequest::vfunc_6 (6 B): matches/0x00273740.cpp
// sym: ?vfunc_6@FileCompletionRequest@core@@UAEHXZ
// Same code shape as 0x00050230 (propagated; names are from that function)
int core::FileCompletionRequest::vfunc_6() {
    return 10;
}

