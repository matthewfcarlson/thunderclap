// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012a740..0x0012a7f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::ProjectileDistanceCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fec170fd {
#define TREE_TU_END }
namespace fn_fec170fd {} using namespace fn_fec170fd;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fec170fd {
class TrackFactoryTemplate_12a740 {
  public:
    TrackFactoryTemplate_12a740() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00128ad0();
extern "C" void* __cdecl alloc(hulk_uintptr);
class TDC_12a780 {
  public:
    hulk_intptr vf;
    char pad[8];
    int x;
    int y;
    unsigned char a;
    unsigned char b;
    void init(int);
};
extern int g_vftable_12a7c0;
struct ConditionFactoryTemplate_12a7c0 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fec170fd

// 0x0012a740 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_1 (60 B): matches/0x0012a740.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VProjectileDistanceCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12a740));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12a740* t = new (mem) TrackFactoryTemplate_12a740();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00128ad0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fec170fd {

// 0x0012a780 fight::ConditionFactoryTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_5 (56 B): matches/0x0012a780.cpp
// sym: ?target@fn_fec170fd@@YAPAVTDC_12a780@1@XZ
// Same code shape as 0x0012a410 (propagated; names are from that function)
TDC_12a780* __cdecl target() {
    TDC_12a780* p = (TDC_12a780*)alloc(0x18);
    int z = 0;
    if (p) {
        p->init(z);
        p->x = z;
        p->y = z;
        p->a = (unsigned char)z;
        p->b = (unsigned char)z;
        p->vf = (hulk_intptr)&tdcVtable;
        return p;
    }
    return 0;
}


// 0x0012a7c0 fight::ConditionFactoryTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_2 (43 B): matches/0x0012a7c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_12a7c0@fn_fec170fd@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_12a7c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_12a7c0;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fec170fd
