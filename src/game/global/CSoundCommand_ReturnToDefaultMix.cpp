// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef7e0..0x001ef900 (kind game, layer game, confidence medium), dominant class CSoundCommand_ReturnToDefaultMix
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_feccf129 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_feccf129 {} using namespace fn_feccf129;
namespace fn_feccf129 { extern "C" char DAT_004245a4[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_feccf129 {
class CSoundCommand_1ef7e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1ef7e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
struct Mgr_1ef800 {
    void Set_001e9b20(int n);
};
struct Owner_1ef800 {
    char pad[4];
    Mgr_1ef800* mgr;
};
class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int a, int b);
};
class CSoundCommand_ReturnToDefaultMix : public CSoundCommand {
  public:
    char pad[0xc];
    float mValue;
    virtual void vfunc_1(int a, int b);
};


// 0x001ef7e0 CSoundCommand_ReturnToDefaultMix::vfunc_0 (31 B): matches/0x001ef7e0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_feccf129@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004245a4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001ef800 CSoundCommand_ReturnToDefaultMix::vfunc_1 (25 B): matches/0x001ef800.cpp
// sym: ?vfunc_1@CSoundCommand_ReturnToDefaultMix@fn_feccf129@@UAEXHH@Z
// data: gOwner = DAT_004e370c
void CSoundCommand_ReturnToDefaultMix::vfunc_1(int a, int b) {
    (*(Owner_1ef800**)&DAT_004e370c)->mgr->Set_001e9b20((int)(__int64)mValue);
}

} // namespace fn_feccf129
