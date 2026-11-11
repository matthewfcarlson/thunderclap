// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275750..0x002757f0 (kind game, layer engine, confidence medium), dominant class core::DriveMediaRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_ff8d14c6 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff8d14c6 {} using namespace fn_ff8d14c6;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ff8d14c6 {
struct DriveRequest_275750 {
    virtual void Run();
    int dummy;
    DriveRequest_275750(int x);
};
struct DriveMediaRequest_275750 : DriveRequest_275750 {
    int b;
    int value;
    DriveMediaRequest_275750(hulk_intptr x, int y);
};
extern void* hulk_at_0042b9bc[];
class Pool_275780 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*);
};
class B_275780 {
  public:
    virtual void v0();
    virtual void v1();
};
class Big_275780 {
  public:
    virtual void v0();
    virtual void v1();
    B_275780 sub;
    char pad[0xc];
    int cnt;
};
class DriveMediaRequest_275780 {
  public:
    void* vptr;
    char pad[4];
    Big_275780* m8;
    DriveMediaRequest_275780* f0(unsigned char flags);
};


// 0x00275750 FUN_00275750 (37 B): matches/0x00275750.cpp
// sym: ??0DriveMediaRequest_275750@fn_ff8d14c6@@QAE@HH@Z
// Same code shape as 0x00275390 (propagated; names are from that function)
DriveMediaRequest_275750::DriveMediaRequest_275750(hulk_intptr x, int y) : DriveRequest_275750(x) {
    value = y;
    FinishInit();
}


// 0x00275780 core::DriveMediaRequest::vfunc_0 (102 B): matches/0x00275780.cpp
// sym: ?f0@DriveMediaRequest_275780@fn_ff8d14c6@@QAEPAV12@E@Z
// data: g_lock_275780 = DAT_0052a1c8, g_pool_275780 = DAT_0052a1e4
DriveMediaRequest_275780* DriveMediaRequest_275780::f0(unsigned char flags) {
    Big_275780* p = m8;
    vptr = hulk_at_0042b9bc;
    p->sub.v0();
    m8->cnt--;
    m8->sub.v1();
    m8->v1();
    vptr = g_base_vftable;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Pool_275780**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_ff8d14c6
