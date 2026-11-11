// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274d80..0x00274e60 (kind game, layer engine, confidence medium), dominant class core::DriveCompletionRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f27978d8 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f27978d8 {} using namespace fn_f27978d8;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f27978d8 {
extern "C" char DAT_0042b978[];
class Obj_274d80 {
  public:
    virtual void A();
};
class Elem_274d80 {
  public:
    virtual void A();
    virtual void B();
};
extern void FUN_002705f0();
struct DriveCompletionRequest_274d80 {
    hulk_intptr vf, p4, p8;
    Obj_274d80* pC;
    Obj_274d80* p10;
    int p14;
    DriveCompletionRequest_274d80(int, int, Obj_274d80*, int);
};
typedef unsigned char u8_274e00;
struct Obj_274e00 {
    virtual void f0();
    virtual void f1();
};
namespace core {
struct DriveCompletionRequest {
    virtual DriveCompletionRequest* vfunc_0(u8_274e00);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad[8];
    Obj_274e00* mAtC;
    Obj_274e00* mAt10;
};
}
struct GlobalObj_274e00 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(core::DriveCompletionRequest*);
};
extern char hulk_at_0042b978[];
extern char hulk_at_0042b914[];


// 0x00274d80 FUN_00274d80 (119 B): matches/0x00274d80.cpp
// sym: ??0DriveCompletionRequest_274d80@fn_f27978d8@@QAE@HHPAVObj_274d80@1@H@Z
DriveCompletionRequest_274d80::DriveCompletionRequest_274d80(int a, int b, Obj_274d80* c, int d) {
    vf = ((hulk_intptr)DAT_0042b914);
    p4 = 0;
    FUN_002705f0();
    vf = ((hulk_intptr)DAT_0042b9dc);
    p8 = a;
    FUN_002705f0();
    vf = ((hulk_intptr)DAT_0042b978);
    pC = (Obj_274d80*)b;
    p10 = c;
    p14 = d;
    FUN_002705f0();
    p10->A();
    ((Elem_274d80*)((char*)pC + 4))->A();
    ++*(int*)((char*)pC + 0x14);
    ((Elem_274d80*)((char*)pC + 4))->B();
    pC->A();
}


// 0x00274e00 core::DriveCompletionRequest::vfunc_0 (82 B): matches/0x00274e00.cpp
// sym: ?vfunc_0@DriveCompletionRequest@core@fn_f27978d8@@UAEPAU123@E@Z
// Same code shape as 0x00274d20 (propagated; names are from that function)
// data: gLock_274e00 = DAT_0052a1c8, gObject_274e00 = DAT_0052a1e4
core::DriveCompletionRequest* core::DriveCompletionRequest::vfunc_0(u8_274e00 param) {
    *(void**)this = hulk_at_0042b978;
    mAt10->f1();
    mAtC->f1();
    *(void**)this = hulk_at_0042b914;
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(GlobalObj_274e00**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f27978d8
