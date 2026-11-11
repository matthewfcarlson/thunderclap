// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274630..0x002746e0 (kind game, layer engine, confidence high), dominant class core::DriveCreateDirectoryRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f5751ba0 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5751ba0 {} using namespace fn_f5751ba0;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f5751ba0 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274630 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
class Service_274670 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual int a15(int*);
};
class Helper_274670 {
  public:
    int Run_00272880();
};
struct Manager_274670 {
    virtual void Reset();
    virtual void Finish();
};
struct Data_274670 {
    char pad[4];
    Manager_274670 manager;
    char pad2[4];
    Service_274670* service;
    char pad3[8];
    int stored;
};
class HalStream_2746c0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
};
class DriveRequest_2746d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int vfunc_6();
};

} // namespace fn_f5751ba0

// 0x00274630 FUN_00274630 (53 B): matches/0x00274630.cpp
// sym: ?FUN_00274630@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_00274630() {
    Obj_274630* p = (*(Obj_274630 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)(*(Obj_274630 * *)&this->f_08) + 0x14));
    p = (*(Obj_274630 * *)&this->f_08);
    p->sub.B();
    p = (*(Obj_274630 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x00274670 core::DriveCreateDirectoryRequest::vfunc_1 (68 B): matches/0x00274670.cpp
// sym: ?vfunc_1@DriveCreateDirectoryRequest@core@@UAEHXZ
int core::DriveCreateDirectoryRequest::vfunc_1() {
    Service_274670* svc = (*(Data_274670 * *)&this->f_08)->service;
    int value = svc->a15((int*)((char*)this + 12));
    int result = ((Helper_274670*)svc)->Run_00272880();
    (*(Data_274670 * *)&this->f_08)->manager.Reset();
    (*(Data_274670 * *)&this->f_08)->stored = result;
    (*(Data_274670 * *)&this->f_08)->manager.Finish();
    return value;
}


// 0x002746c0 core::DriveCreateDirectoryRequest::vfunc_5 (4 B): matches/0x002746c0.cpp
// sym: ?vfunc_5@DriveCreateDirectoryRequest@core@@UAEPAXXZ
// Same code shape as 0x0025c0b0 (propagated; names are from that function)
 // namespace audio
void* core::DriveCreateDirectoryRequest::vfunc_5() {
    return (void*)((core::DriveCreateDirectoryRequest*)((char*)this + 0xc));
}


// 0x002746d0 core::DriveCreateDirectoryRequest::vfunc_6 (6 B): matches/0x002746d0.cpp
// sym: ?vfunc_6@DriveCreateDirectoryRequest@core@@UAEHXZ
int core::DriveCreateDirectoryRequest::vfunc_6() {
    return 0xe;
}

