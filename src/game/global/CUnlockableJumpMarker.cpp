// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000934d0..0x00093570 (kind game, layer game, confidence medium), dominant class CUnlockableJumpMarker
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f6003de1 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6003de1 {} using namespace fn_f6003de1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6003de1 {
class Inner_93530 {
  public:
    void Reset();
};
class CUnlockableJumpMarker_93530 {
  public:
    virtual ~CUnlockableJumpMarker_93530();
    char pad[0x14];
    void* mPtr18;
};

} // namespace fn_f6003de1

// 0x000934d0 FUN_000934d0 (90 B): matches/0x000934d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CUnlockableMove@fn_000934d0@@QAE@H@Z
namespace fn_000934d0 {
class Part_934d0 {
  public:
    Part_934d0();
    char pad[8];
};
class CUnlockableMove_934d0 {
  public:
    CUnlockableMove_934d0();
    virtual void f();
    char pad4[4];
    char flag8;
    char pad9[7];
    Part_934d0 p10;
    int val18;
};
CUnlockableMove_934d0::CUnlockableMove_934d0() : flag8(1), val18(0) {}
class CUnlockableMove : public CUnlockableMove_934d0 {
  public:
    CUnlockableMove(int x);
    virtual void g();
    void Init(int x);
    char pad1c[4];
    char flag20;
    char pad21[3];
    int val24;
    int val28;
    char flag2c;
    char pad2d[3];
    int val30;
    char pad34[4];
    Part_934d0 p38;
    Part_934d0 p40;
    char flag48;
};
CUnlockableMove::CUnlockableMove(int x) : flag20(0), val24(0), val28(-1), flag2c(0), val30(0), flag48(0) {
    Init(x);
}
} // namespace fn_000934d0

namespace fn_f6003de1 {

// 0x00093530 CUnlockableJumpMarker::vfunc_0 (62 B): matches/0x00093530.cpp
// sym: ??_GCUnlockableJumpMarker_93530@fn_f6003de1@@UAEPAXI@Z
// Same code shape as 0x000933a0 (propagated; names are from that function)
CUnlockableJumpMarker_93530::~CUnlockableJumpMarker_93530() {
    if (mPtr18) {
        FreeMem(mPtr18);
        mPtr18 = 0;
    }
    ((Inner_93530*)((char*)this + 0x10))->Reset();
}

} // namespace fn_f6003de1
