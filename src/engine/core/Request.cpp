// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00274af0..0x00274ba0 (kind game, layer engine, confidence medium), dominant class core::Request
#include "tree_prelude.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f787d2f4 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f787d2f4 {} using namespace fn_f787d2f4;
namespace fn_f787d2f4 { extern "C" char DAT_0042b914[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f787d2f4 {
struct Obj_274af0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(void*, void*, void*);
};
class Request_274b40 {
  public:
    virtual ~Request_274b40();
    int value;
    Request_274b40();
};
void FUN_002705f0();
struct Manager_274b60 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
namespace core {
struct Request {
    void** vt;
    Request* vfunc_0(unsigned char);
};
}


// 0x00274af0 FUN_00274af0 (66 B): matches/0x00274af0.cpp
// sym: _FUN_00274af0
// data: gData_274af0 = DAT_0052a1c8
extern "C" void FUN_00274af0() {
    char a[4], b[4], c[4];
    FUN_0026d830(((char*)&DAT_0052a1c8));
    (*(Obj_274af0**)&DAT_0052a1e4)->f14(a, b, c);
    (*(Obj_274af0**)&DAT_0052a1e4)->f1();
    (*(Obj_274af0**)&DAT_0052a1e4) = 0;
}


// 0x00274b40 FUN_00274b40 (25 B): matches/0x00274b40.cpp
// sym: ??0Request_274b40@fn_f787d2f4@@QAE@XZ
// Same code shape as 0x002704d0 (propagated; names are from that function)
Request_274b40::Request_274b40() {
    value = 0;
    FUN_002705f0();
}


// 0x00274b60 core::Request::vfunc_0 (60 B): matches/0x00274b60.cpp
// sym: ?vfunc_0@Request@core@fn_f787d2f4@@QAEPAU123@E@Z
// data: g_lock_274b60 = DAT_0052a1c8, g_manager_274b60 = DAT_0052a1e4
core::Request* core::Request::vfunc_0(unsigned char param) {
    vt = ((void**)DAT_0042b914);
    if (param & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Manager_274b60**)&DAT_0052a1e4)->e(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f787d2f4
