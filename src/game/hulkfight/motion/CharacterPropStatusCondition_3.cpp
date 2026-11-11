// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016dd80..0x0016de30 (kind game, layer game, confidence high), dominant class hulkfight::motion::CharacterPropStatusCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb3e6666 {
#define TREE_TU_END }
namespace fn_fb3e6666 {} using namespace fn_fb3e6666;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fb3e6666 {
class TrackFactoryTemplate_16dd80 {
  public:
    TrackFactoryTemplate_16dd80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_0016b920();
extern "C" char DAT_00416898[];
class Character {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
    int x;
    int y;
    Character(int);
};
extern "C" void* Alloc(hulk_uintptr);
extern int hulk_at_004176b8;
struct ConditionFactoryTemplate_16de00 {
    void* m_vptr;
    void base1_dtor_00166290();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fb3e6666

// 0x0016dd80 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_1 (60 B): matches/0x0016dd80.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_16dd80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_16dd80* t = new (mem) TrackFactoryTemplate_16dd80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0016b920();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0016ddc0 fight::ConditionFactoryTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_5 (54 B): matches/0x0016ddc0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCharacterPropStatusCondition@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_5() {
    Character* p = (Character*)Alloc(0x14);
    if (p) {
        p->Character::Character(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00416898);
        p->x = 0;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fb3e6666 {

// 0x0016de00 fight::ConditionFactoryTemplate<hulkfight::motion::CharacterPropStatusCondition>::vfunc_2 (43 B): matches/0x0016de00.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_16de00@fn_fb3e6666@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_16de00::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004176b8;
    base1_dtor_00166290();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fb3e6666
