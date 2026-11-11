// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00075d70..0x00075e30 (kind game, layer game, confidence high), dominant class CCameraHintTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff6e009a {
#define TREE_TU_END }
namespace fn_ff6e009a {} using namespace fn_ff6e009a;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ff6e009a {
class TrackFactoryTemplate_75d70 {
  public:
    TrackFactoryTemplate_75d70() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00071cc0();
extern int hulk_at_003fe578;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0006a4d0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_ff6e009a

// 0x00075d70 fight::TrackFactoryCasterTemplate<CCameraHintTrack>::vfunc_1 (60 B): matches/0x00075d70.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCCameraHintTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CCameraHintTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_75d70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_75d70* t = new (mem) TrackFactoryTemplate_75d70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00071cc0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00075db0 fight::TrackFactoryTemplate<CCameraHintTrack>::vfunc_5 (66 B): matches/0x00075db0.cpp [wrapped: conflict: content::LoadObject; core::IRefCount; fight::TrackFactory; pure3d::Entity]
// sym: ?vfunc_5@TrackFactoryTemplate_CCameraHintTrack@fn_00075db0@@QAEPAXXZ
namespace fn_00075db0 {
extern "C" char DAT_003fbef4[];
namespace fight {
class TrackFactory {};
} // namespace fight
namespace pure3d {
class Entity {};
} // namespace pure3d
namespace content {
class LoadObject {};
} // namespace content
namespace core {
class IRefCount {};
} // namespace core

class TrackFactoryTemplate_CCameraHintTrack : public fight::TrackFactory,
                                              public pure3d::Entity,
                                              public content::LoadObject,
                                              public core::IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    void* vfunc_5();
};

extern "C" void* FUN_0008d690(unsigned int);

struct InternalHelper {
    void CallFunc_00236d40();
};

void* TrackFactoryTemplate_CCameraHintTrack::vfunc_5() {
    void* ptr = FUN_0008d690(0x18);
    if (ptr != 0) {
        static_cast<InternalHelper*>(ptr)->CallFunc_00236d40();
        *(hulk_uintptr*)ptr = ((hulk_intptr)DAT_003fbef4);
        ((unsigned int*)ptr)[3] = 0;
        ((float*)ptr)[4] = -1.0f;
        ((unsigned int*)ptr)[5] = 0;
        ((unsigned int*)ptr)[2] = 1;
        return ptr;
    }
    return 0;
}
} // namespace fn_00075db0

namespace fn_ff6e009a {

// 0x00075e00 fight::TrackFactoryTemplate<CCameraHintTrack>::vfunc_2 (43 B): matches/0x00075e00.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ff6e009a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003fe578;
    base1_dtor_0006a4d0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ff6e009a
