// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093570..0x000935b0 (kind game, layer game, confidence medium), dominant class CUnlockableMovie
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f0e6ff5d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0e6ff5d {} using namespace fn_f0e6ff5d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0e6ff5d {
class Inner_93570 {
  public:
    void Reset_0027af50();
};
class CUnlockableMovie_93570 {
  public:
    virtual ~CUnlockableMovie_93570();
    char pad[0x14];
    void* mPtr18;
};


// 0x00093570 CUnlockableMovie::vfunc_0 (62 B): matches/0x00093570.cpp
// sym: ??_GCUnlockableMovie_93570@fn_f0e6ff5d@@UAEPAXI@Z
// Same code shape as 0x000933a0 (propagated; names are from that function)
CUnlockableMovie_93570::~CUnlockableMovie_93570() {
    if (mPtr18) {
        FreeMem(mPtr18);
        mPtr18 = 0;
    }
    ((Inner_93570*)((char*)this + 0x10))->Reset_0027af50();
}

} // namespace fn_f0e6ff5d
