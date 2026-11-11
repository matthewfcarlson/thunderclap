// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00077530..0x000775e0 (kind game, layer game, confidence high), dominant class CSoundTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe9702db {
#define TREE_TU_END }
namespace fn_fe9702db {} using namespace fn_fe9702db;
#include "game/global.h"

// ---- declarations shared by the functions below
void* __cdecl operator new(size_t size);
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe9702db {
class TrackFactoryTemplate_77530 {
  public:
    TrackFactoryTemplate_77530() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
class Base_77570 {
  public:
    Base_77570();
    virtual void bv();
    int bx;
};
class CSoundTrack_77570 : public Base_77570 {
  public:
    CSoundTrack_77570() : Base_77570() {
        zero = 0;
        flag = 0;
        flag2 = 0;
        one = 1;
    }
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int one;
    int zero;
    unsigned char flag;
    char pad[0x3f];
    unsigned char flag2;
};
extern "C" void* FUN_0008d690(unsigned int);
extern int hulk_at_003feb14;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00069690();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_fe9702db

// 0x00077530 fight::TrackFactoryCasterTemplate<CSoundTrack>::vfunc_1 (60 B): matches/0x00077530.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCSoundTrack@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<CSoundTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_77530));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_77530* t = new (mem) TrackFactoryTemplate_77530();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00070d50();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00077570 fight::TrackFactoryTemplate<CSoundTrack>::vfunc_5 (60 B): matches/0x00077570.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VCSoundTrack@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<CSoundTrack>::vfunc_5() {
    CSoundTrack_77570* p = (CSoundTrack_77570*)FUN_0008d690((int)sizeof(CSoundTrack_77570));
    if (p) {
        p->CSoundTrack_77570::CSoundTrack_77570();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe9702db {

// 0x000775b0 fight::TrackFactoryTemplate<CSoundTrack>::vfunc_2 (43 B): matches/0x000775b0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fe9702db@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_003feb14;
    base1_dtor_00069690();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fe9702db
