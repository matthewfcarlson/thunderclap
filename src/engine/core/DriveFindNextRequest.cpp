// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002759e0..0x00275b40 (kind game, layer engine, confidence medium), dominant class core::DriveFindNextRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#define TREE_TU_BEGIN namespace fn_f105060a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f105060a {} using namespace fn_f105060a;
namespace fn_f105060a { extern "C" char DAT_0042b914[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f105060a {
extern "C" char DAT_0042bc00[];
} // namespace fn_f105060a
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f105060a {
class DriveFindFirstRequest {
  public:
    virtual void V0();
    void InitBase_00275600(void*);
    DriveFindFirstRequest* Init(void* a, char* src, int v);
    char pad0[8];
    char name[0x100];
    char pad[4];
    int value;
};
extern int hulk_at_0042b9bc, hulk_at_0042b914;
class Elem_275a30 {
  public:
    virtual void A();
    virtual void B();
};
class G_275a30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
namespace core {
class DriveFindFirstRequest {
  public:
    virtual DriveFindFirstRequest* vfunc_0(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int pad;
    Elem_275a30* object;
};
}
struct DriveRequest_275aa0 {
    virtual void* Run_00275ad0(char);
    int dummy;
    DriveRequest_275aa0(int x);
};
struct DriveFindNextRequest_275aa0 : DriveRequest_275aa0 {
    int b;
    int value;
    DriveFindNextRequest_275aa0(hulk_intptr x, int y);
};
extern void* g_vftable_275ad0[];
class Pool_275ad0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*);
};
class B_275ad0 {
  public:
    virtual void v0();
    virtual void v1();
};
class Big_275ad0 {
  public:
    virtual void v0();
    virtual void v1();
    B_275ad0 sub;
    char pad[0xc];
    int cnt;
};
class DriveFindNextRequest_275ad0 {
  public:
    void* vptr;
    char pad[4];
    Big_275ad0* m8;
    DriveFindNextRequest_275ad0* f0(unsigned char flags);
};


// 0x002759e0 FUN_002759e0 (69 B): matches/0x002759e0.cpp
// sym: ?Init@DriveFindFirstRequest@fn_f105060a@@QAEPAV12@PAXPADH@Z
DriveFindFirstRequest* DriveFindFirstRequest::Init(void* a, char* src, int v) {
    InitBase_00275600(a);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042bc00);
    value = v;
    InitMore();
    strncpy(name, src, 0x100);
    name[0x100] = 0;
    return this;
}


// 0x00275a30 core::DriveFindFirstRequest::vfunc_0 (102 B): matches/0x00275a30.cpp
// sym: ?vfunc_0@DriveFindFirstRequest@core@fn_f105060a@@UAEPAV123@H@Z
// data: globalG = DAT_0052a1e4
core::DriveFindFirstRequest* core::DriveFindFirstRequest::vfunc_0(int flag) {
    ((hulk_intptr*)this)[0] = (hulk_intptr)&hulk_at_0042b9bc;
    ((Elem_275a30*)((char*)object + 4))->A();
    --((int*)((char*)object))[5];
    ((Elem_275a30*)((char*)object + 4))->B();
    object->B();
    ((hulk_intptr*)this)[0] = (hulk_intptr)&hulk_at_0042b914;
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
        (*(G_275a30**)&DAT_0052a1e4)->e(this);
        FUN_0026d840((void*)((hulk_intptr)((char*)&DAT_0052a1c8)));
    }
    return this;
}


// 0x00275aa0 FUN_00275aa0 (37 B): matches/0x00275aa0.cpp
// sym: ??0DriveFindNextRequest_275aa0@fn_f105060a@@QAE@HH@Z
// Same code shape as 0x00275390 (propagated; names are from that function)
DriveFindNextRequest_275aa0::DriveFindNextRequest_275aa0(hulk_intptr x, int y) : DriveRequest_275aa0(x) {
    value = y;
    FinishInit();
}


// 0x00275ad0 core::DriveFindNextRequest::vfunc_0 (102 B): matches/0x00275ad0.cpp
// sym: ?f0@DriveFindNextRequest_275ad0@fn_f105060a@@QAEPAV12@E@Z
// data: g_lock_275ad0 = DAT_0052a1c8, g_pool_275ad0 = DAT_0052a1e4
DriveFindNextRequest_275ad0* DriveFindNextRequest_275ad0::f0(unsigned char flags) {
    Big_275ad0* p = m8;
    vptr = g_vftable_275ad0;
    p->sub.v0();
    m8->cnt--;
    m8->sub.v1();
    m8->v1();
    vptr = (void**)DAT_0042b914;
    if (flags & 1) {
        FUN_0026d850(((char*)&DAT_0052a1c8));
        (*(Pool_275ad0**)&DAT_0052a1e4)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1c8));
    }
    return this;
}

} // namespace fn_f105060a
