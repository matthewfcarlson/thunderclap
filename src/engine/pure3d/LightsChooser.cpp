// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029f570..0x0029f600 (kind game, layer engine, confidence medium), dominant class pure3d::LightsChooser::CacheManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f0d14b71 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f0d14b71 {} using namespace fn_f0d14b71;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f0d14b71 {
class CAction_29f570 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_29f570* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CacheManager_29f570 : public CAction_29f570 {
  public:
    CacheManager_29f570* vfunc_2(unsigned char);
};
struct CacheManager_nv_29f570 {
    void FUN_0029f590();
};
extern void thunk_FUN_00267090(CacheManager_29f570*);
class Item_29f590 {
  public:
    virtual void A();
    virtual void B();
};
class End_29f590 {
  public:
};
class CacheManager_29f590 {
  public:
    virtual void* FnV_0029f570(char);
    int pad04[9];
    hulk_intptr m28;
    hulk_intptr m2c;
    hulk_intptr m30;
    int m34;
    ~CacheManager_29f590();
};
void __cdecl Free_0008d340(void*);
void __cdecl Free2_0008d340(void*);
void __cdecl Free3_0008d330(void*);


// 0x0029f570 pure3d::LightsChooser::CacheManager::vfunc_0 (30 B): matches/0x0029f570.cpp
// sym: ?vfunc_2@CacheManager_29f570@fn_f0d14b71@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CacheManager_29f570* CacheManager_29f570::vfunc_2(unsigned char flags) {
    ((CacheManager_nv_29f570*)(((pure3d::LightsChooser::CacheManager*)(this))))->FUN_0029f590();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x0029f590 FUN_0029f590 (99 B): matches/0x0029f590.cpp
// sym: ??1CacheManager_29f590@fn_f0d14b71@@QAE@XZ
CacheManager_29f590::~CacheManager_29f590() {
    int i = 0;
    if (m34 > 0) {
        for (; i < m34; ++i) {
            Item_29f590* p = *(Item_29f590**)(*(char**)((char*)&this->m2c) + i * 0x1c + 0xc);
            p->B();
        }
    }
    Free_0008d340((void*)m30);
    if (m2c != 0)
        Free2_0008d340((char*)m2c - 4);
    Free3_0008d330((void*)m28);
    ((owners::C_231050 *)(((End_29f590*)((char*)this + 4))))->FUN_00231050();
}

} // namespace fn_f0d14b71
