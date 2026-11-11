// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093430..0x00093470 (kind game, layer game, confidence medium), dominant class CUnlockableCheat
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fdecd08a {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fdecd08a {} using namespace fn_fdecd08a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fdecd08a {
class Inner_93430 {
  public:
    void Reset();
};
class CUnlockableCheat_93430 {
  public:
    virtual ~CUnlockableCheat_93430();
    char pad[0x14];
    void* mPtr18;
};


// 0x00093430 CUnlockableCheat::vfunc_0 (62 B): matches/0x00093430.cpp
// sym: ??_GCUnlockableCheat_93430@fn_fdecd08a@@UAEPAXI@Z
// Same code shape as 0x000933a0 (propagated; names are from that function)
CUnlockableCheat_93430::~CUnlockableCheat_93430() {
    if (mPtr18) {
        FreeMem(mPtr18);
        mPtr18 = 0;
    }
    ((Inner_93430*)((char*)this + 0x10))->Reset();
}

} // namespace fn_fdecd08a
