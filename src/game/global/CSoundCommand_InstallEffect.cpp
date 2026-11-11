// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0a10..0x001f0ab0 (kind game, layer game, confidence medium), dominant class CSoundCommand_InstallEffect
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f12cce35 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f12cce35 {} using namespace fn_f12cce35;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f12cce35 {
class CSoundCommand_1f0a10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0a10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
struct SoundSystem { void FUN_001ea560(unsigned int effect, unsigned int value); };
struct SoundGlobal { char pad[4]; SoundSystem* system; };
class CSoundCommand {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_InstallEffect : public CSoundCommand {
public:
    char pad[12];
    unsigned int effect;
    unsigned int value;
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};


// 0x001f0a10 CSoundCommand_InstallEffect::vfunc_0 (31 B): matches/0x001f0a10.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f12cce35@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001f0a30 CSoundCommand_InstallEffect::vfunc_1 (33 B): equivalent/0x001f0a30.cpp
// sym: ?vfunc_1@CSoundCommand_InstallEffect@fn_f12cce35@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CSoundCommand_InstallEffect::vfunc_1 @ 0x001f0a30
void CSoundCommand_InstallEffect::vfunc_1(int, int) {
    (*(SoundGlobal**)&DAT_004e370c)->system->FUN_001ea560(effect, value);
}

} // namespace fn_f12cce35
