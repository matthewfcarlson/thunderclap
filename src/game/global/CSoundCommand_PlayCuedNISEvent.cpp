// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef6b0..0x001ef700 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayCuedNISEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f1a46913 {
#define TREE_TU_END }
namespace fn_f1a46913 {} using namespace fn_f1a46913;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f1a46913 {
class Singleton_1ef6d0 {
  public:
    void Run_001f6ba0();
};

} // namespace fn_f1a46913

// 0x001ef6b0 CSoundCommand_PlayCuedNISEvent::vfunc_0 (31 B): matches/0x001ef6b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001ef6b0@@UAEPAV123@E@Z
namespace fn_001ef6b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1ef6b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_004245a4[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1ef6b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_004245a4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001ef6b0


// 0x001ef6d0 CSoundCommand_PlayCuedNISEvent::vfunc_1 (15 B): matches/0x001ef6d0.cpp
// sym: ?vfunc_1@CSoundCommand_PlayCuedNISEvent@@UAEXHH@Z
// data: gSingleton_1ef6d0 = DAT_004e370c
void CSoundCommand_PlayCuedNISEvent::vfunc_1(int , int ) {
    (*(*(Singleton_1ef6d0***)&DAT_004e370c))->Run_001f6ba0();
}

