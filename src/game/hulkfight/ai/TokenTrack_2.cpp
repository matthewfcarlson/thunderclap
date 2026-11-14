// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114d30..0x00114de0 (kind game, layer game, confidence high), dominant class hulkfight::ai::TokenTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe1f4182 {
#define TREE_TU_END }
namespace fn_fe1f4182 {} using namespace fn_fe1f4182;
namespace fn_fe1f4182 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
}
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe1f4182 {
class TrackFactoryTemplate_114d30 {
  public:
    TrackFactoryTemplate_114d30() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00112e30();
} // namespace fn_fe1f4182
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace hulkfight { namespace ai {
class BaseTrack {
  public:
    BaseTrack();
    virtual void v0();
    char pad[4];
};
} }
namespace hulkfight { namespace ai {
class TokenTrack_114d70 : public BaseTrack {
  public:
    TokenTrack_114d70() {
        *(int*)((char*)this + 12) = 0;
        *(float*)((char*)this + 16) = -1.0f;
        *((char*)this + 20) = 0;
        *(int*)((char*)this + 8) = 1;
    }
    virtual void v0();
    char pad2[16];
};
} }
namespace fn_fe1f4182 {
extern char hulk_at_0040ea48;
class TokenTrack;
class TrackFactoryTemplate {
  public:
    void* mVptr;
    void Dtor_Base1_0010d4a0();
    void Dtor_Base2_00236ab0();
    void* DeletingDtor(unsigned char flags);
};
void DeallocateObject_00263f30(void* p);

} // namespace fn_fe1f4182

// 0x00114d30 fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_1 (60 B): matches/0x00114d30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VTokenTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_114d30));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_114d30* t = new (mem) TrackFactoryTemplate_114d30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00112e30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00114d70 fight::TrackFactoryTemplate<hulkfight::ai::TokenTrack>::vfunc_5 (63 B): matches/0x00114d70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VTokenTrack@ai@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::TokenTrack>::vfunc_5() {
    return (void*)(new hulkfight::ai::TokenTrack_114d70);
}

namespace fn_fe1f4182 {

// 0x00114db0 fight::TrackFactoryTemplate<hulkfight::ai::TokenTrack>::vfunc_2 (43 B): matches/0x00114db0.cpp
// sym: ?DeletingDtor@TrackFactoryTemplate@fn_fe1f4182@@QAEPAXE@Z
void* TrackFactoryTemplate::DeletingDtor(unsigned char flags) {
    mVptr = &hulk_at_0040ea48;
    Dtor_Base1_0010d4a0();
    Dtor_Base2_00236ab0();
    if (flags & 1) {
        DeallocateObject_00263f30(this);
    }
    return this;
}

} // namespace fn_fe1f4182
