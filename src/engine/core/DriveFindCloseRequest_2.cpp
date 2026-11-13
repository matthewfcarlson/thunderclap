// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275b40..0x00275bd0 (kind game, layer engine, confidence medium), dominant class core::DriveFindCloseRequest
#include "tree_prelude.h"
#include "decls/instance_drive.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_fe4a9338 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe4a9338 {} using namespace fn_fe4a9338;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fe4a9338 {
class DriveRequest_275b40 {
  public:
    DriveRequest_275b40(unsigned int);
    virtual void Fn();
};
class DriveFindCloseRequest : public DriveRequest_275b40 {
  public:
    DriveFindCloseRequest(hulk_uintptr);
    virtual void Fn();
};
extern void FUN_002705f0();
typedef unsigned char byte_275b60;
struct O_275b60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
    virtual void f();
    virtual void g();
};
struct T_275b60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
namespace core {
struct DriveFindCloseRequest {
    virtual DriveFindCloseRequest* vfunc_0(byte_275b60);
    char pad[4];
    HulkInstanceDrive* field8;   // (x64t10) decls/instance_drive.h
};
}


// 0x00275b40 FUN_00275b40 (30 B): matches/0x00275b40.cpp
// sym: ??0DriveFindCloseRequest@fn_fe4a9338@@QAE@I@Z
DriveFindCloseRequest::DriveFindCloseRequest(hulk_uintptr x) : DriveRequest_275b40(x) {
    FUN_002705f0();
}


// 0x00275b60 core::DriveFindCloseRequest::vfunc_0 (102 B): matches/0x00275b60.cpp
// sym: ?vfunc_0@DriveFindCloseRequest@core@fn_fe4a9338@@UAEPAU123@E@Z
// data: glob_275b60 = DAT_0052a1e4
core::DriveFindCloseRequest* core::DriveFindCloseRequest::vfunc_0(byte_275b60 flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042b9bc);
    ((O_275b60*)&field8->mutableVftable)->a();
    field8->pending--;
    ((O_275b60*)&field8->mutableVftable)->b();
    ((O_275b60*)field8)->b();
    *(void**)this = (void*)((hulk_intptr)DAT_0042b914);
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        (*(O_275b60**)&DAT_0052a1e4)->e(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}

} // namespace fn_fe4a9338
