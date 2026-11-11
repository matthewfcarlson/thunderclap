// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002757f0..0x00275880 (kind game, layer engine, confidence medium), dominant class core::DriveFormatRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_fc6c79c4 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc6c79c4 {} using namespace fn_fc6c79c4;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fc6c79c4 {
class DriveRequest_2757f0 {
  public:
    virtual void V();
    DriveRequest_2757f0(int);
};
class DriveFormatRequest : public DriveRequest_2757f0 {
  public:
    virtual void W();
    DriveFormatRequest(hulk_intptr);
};
extern void* g_vftable_275810[];
class Pool_275810 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*);
};
class B_275810 {
  public:
    virtual void v0();
    virtual void v1();
};
class Big_275810 {
  public:
    virtual void v0();
    virtual void v1();
    B_275810 sub;
    char pad[0xc];
    int cnt;
};
class DriveFormatRequest_275810 {
  public:
    void* vptr;
    char pad[4];
    Big_275810* m8;
    DriveFormatRequest_275810* f0(unsigned char flags);
};


// 0x002757f0 FUN_002757f0 (30 B): matches/0x002757f0.cpp
// sym: ??0DriveFormatRequest@fn_fc6c79c4@@QAE@H@Z
DriveFormatRequest::DriveFormatRequest(hulk_intptr x) : DriveRequest_2757f0(x) {
    FinishInit();
}


// 0x00275810 core::DriveFormatRequest::vfunc_0 (102 B): matches/0x00275810.cpp
// sym: ?f0@DriveFormatRequest_275810@fn_fc6c79c4@@QAEPAV12@E@Z
// data: g_lock_275810 = DAT_0052a1c8, g_pool_275810 = DAT_0052a1e4
DriveFormatRequest_275810* DriveFormatRequest_275810::f0(unsigned char flags) {
    Big_275810* p = m8;
    vptr = g_vftable_275810;
    p->sub.v0();
    m8->cnt--;
    m8->sub.v1();
    m8->v1();
    vptr = g_base_vftable;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Pool_275810**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_fc6c79c4
