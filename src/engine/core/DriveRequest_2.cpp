// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275600..0x002756e0 (kind game, layer engine, confidence medium), dominant class core::DriveRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/instance_drive.h"
#define TREE_TU_BEGIN namespace fn_f57d136c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f57d136c {} using namespace fn_f57d136c;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f57d136c {
extern void* hulk_at_0042b914[];
class Elem_275600 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_275600 {
  public:
    virtual void A();
};
extern "C" int* __cdecl FUN_002705f0();   // (x64t9) returns a global's address (0x002705f0: `mov eax, imm; ret`)
// (x64t10) the InstanceDrive the request runs on: decls/instance_drive.h's record (its lock is the IMutable
// vftable's object at mutableVftable)
struct DriveRequest_275600 {
    void* vf;
    int p4;
    HulkInstanceDrive* p8;
    DriveRequest_275600(HulkInstanceDrive*);
};
typedef unsigned char byte_275650;
struct O_275650 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
    virtual void f();
    virtual void g();
};
struct T_275650 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
namespace core {
struct DriveRequest {
    virtual DriveRequest* vfunc_0(byte_275650);
    char pad[4];
    HulkInstanceDrive* field8;   // (x64t10) decls/instance_drive.h
};
}
extern "C" char DAT_0042bb60[];
// (x64t9) built on the InstanceDrive it opens (0x00277110 passes `this`): the base constructor 0x00275600 takes it
// and returns `this`, as the constructor it is
class DriveOpenRequest {
  public:
    hulk_intptr vptr;
    void* Init_00275600(HulkInstanceDrive*);
    DriveOpenRequest(HulkInstanceDrive*);
};


// 0x00275600 FUN_00275600 (80 B): matches/0x00275600.cpp
// sym: ??0DriveRequest_275600@fn_f57d136c@@QAE@PAUHulkInstanceDrive@@@Z
DriveRequest_275600::DriveRequest_275600(HulkInstanceDrive* a) {
    vf = hulk_at_0042b914;
    p4 = 0;
    FUN_002705f0();
    vf = vDrive;
    p8 = a;
    FUN_002705f0();
    ((Elem_275600*)&p8->mutableVftable)->A();
    ++p8->pending;
    ((Elem_275600*)&p8->mutableVftable)->B();
    ((Obj_275600*)p8)->A();
}


// 0x00275650 core::DriveRequest::vfunc_0 (102 B): matches/0x00275650.cpp
// sym: ?vfunc_0@DriveRequest@core@fn_f57d136c@@UAEPAU123@E@Z
// data: glob_275650 = DAT_0052a1e4
core::DriveRequest* core::DriveRequest::vfunc_0(byte_275650 flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042b9bc);
    ((O_275650*)&field8->mutableVftable)->a();
    field8->pending--;
    ((O_275650*)&field8->mutableVftable)->b();
    ((O_275650*)field8)->b();
    *(void**)this = (void*)((hulk_intptr)DAT_0042b914);
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        (*(O_275650**)&DAT_0052a1e4)->e(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}


// 0x002756c0 FUN_002756c0 (30 B): matches/0x002756c0.cpp
// sym: ??0DriveOpenRequest@fn_f57d136c@@QAE@PAUHulkInstanceDrive@@@Z
DriveOpenRequest::DriveOpenRequest(HulkInstanceDrive* a) {
    Init_00275600(a);
    vptr = ((hulk_intptr)DAT_0042bb60);
    FUN_002705f0();
}

} // namespace fn_f57d136c
