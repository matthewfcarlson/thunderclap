// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000933a0..0x000933e0 (kind game, layer game, confidence medium), dominant class CUnlockable
#include "tree_prelude.h"
#include "decls/unlockables.h"
#define TREE_TU_BEGIN namespace fn_f35c3e3c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f35c3e3c {} using namespace fn_f35c3e3c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f35c3e3c {
class Inner_933a0 {
  public:
    void Reset_0027af50();
};
class CUnlockable : public HulkUnlockableWords {    // decls/unlockables.h
  public:
    virtual ~CUnlockable();
};


// 0x000933a0 CUnlockable::vfunc_0 (62 B): matches/0x000933a0.cpp
// sym: ??_GCUnlockable@fn_f35c3e3c@@UAEPAXI@Z
CUnlockable::~CUnlockable() {
    if (data) {
        FreeMem(data);
        data = 0;
    }
    ((Inner_933a0*)&this->id)->Reset_0027af50();
}

} // namespace fn_f35c3e3c
