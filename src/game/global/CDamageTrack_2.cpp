// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000761b0..0x00076270 (kind game, layer game, confidence high), dominant class CDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fed05365 {
#define TREE_TU_END }
namespace fn_fed05365 {} using namespace fn_fed05365;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fed05365 {
class TrackFactoryTemplate_761b0 {
  public:
    TrackFactoryTemplate_761b0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_003fbd14[];
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
} // namespace fn_fed05365
struct CDamageTrack {
    hulk_intptr vptr;
    int pad4;
    int pad8;
    int x;
    int y;
    int z;
    void ctor();
};
namespace fn_fed05365 {
extern "C" void* __cdecl alloc(hulk_uintptr);

} // namespace fn_fed05365

// 0x000761b0 fight::TrackFactoryCasterTemplate<CDamageTrack>::vfunc_1 (60 B): matches/0x000761b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@UCDamageTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CDamageTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_761b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_761b0* t = new (mem) TrackFactoryTemplate_761b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071700();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fed05365 {

// 0x000761f0 fight::TrackFactoryTemplate<CDamageTrack>::vfunc_5 (66 B): matches/0x000761f0.cpp
// sym: ?target@fn_fed05365@@YAPAXXZ
void* __cdecl target() {
    CDamageTrack* p = (CDamageTrack*)alloc(0x18);
    if (p) {
        p->ctor();
        p->vptr = ((hulk_intptr)DAT_003fbd14);
        p->x = 0;
        p->y = 0;
        p->z = 0;
        p->pad8 = 1;
        return p;
    }
    return 0;
}

} // namespace fn_fed05365

// 0x00076240 fight::TrackFactoryTemplate<CDamageTrack>::vfunc_2 (43 B): matches/0x00076240.cpp [wrapped: conflict: TrackFactoryTemplate]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00076240@@QAEPAXE@Z
namespace fn_00076240 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int g_vftable_76240;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_76240;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}
} // namespace fn_00076240

