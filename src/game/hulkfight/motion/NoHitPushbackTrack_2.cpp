// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a440..0x0015a4f0 (kind game, layer game, confidence high), dominant class hulkfight::motion::NoHitPushbackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd8b40d2 {
#define TREE_TU_END }
namespace fn_fd8b40d2 {} using namespace fn_fd8b40d2;
namespace fn_fd8b40d2 {
struct FactoryCtor { void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fd8b40d2 {
class TrackFactoryTemplate_15a440 {
  public:
    TrackFactoryTemplate_15a440() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00156bb0();
extern "C" char DAT_004144e0[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Obj_15a480 {
  public:
    virtual void* A();
    virtual void* B();
    virtual void* C();
    virtual void* D();
    virtual void* E();
    virtual void* F();
    void Init_00236d40();
    char pad[4];
    int x;
    int y;
    float z;
};
extern int hulk_at_00415880;

} // namespace fn_fd8b40d2

// 0x0015a440 fight::TrackFactoryCasterTemplate<hulkfight::motion::NoHitPushbackTrack>::vfunc_1 (60 B): matches/0x0015a440.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VNoHitPushbackTrack@motion@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::motion::NoHitPushbackTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_15a440));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_15a440* t = new (mem) TrackFactoryTemplate_15a440();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00156bb0();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fd8b40d2 {

// 0x0015a480 fight::TrackFactoryTemplate<hulkfight::motion::NoHitPushbackTrack>::vfunc_5 (59 B): matches/0x0015a480.cpp
// sym: ?F@Obj_15a480@fn_fd8b40d2@@UAEPAXXZ
void* Obj_15a480::F() {
    Obj_15a480* p = (Obj_15a480*)Alloc(0x14);
    if (p) {
        p->Init_00236d40();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004144e0);
        p->y = 0;
        p->z = -1.0f;
        p->x = 1;
        return p;
    }
    return 0;
}


// 0x0015a4c0 fight::TrackFactoryTemplate<hulkfight::motion::NoHitPushbackTrack>::vfunc_2 (43 B): matches/0x0015a4c0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fd8b40d2@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00415880;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fd8b40d2
