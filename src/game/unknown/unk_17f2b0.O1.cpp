// cl-flags: /O1
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017f2b0..0x00180b60 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fa661594 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa661594 {} using namespace fn_fa661594;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fa661594 {
struct Vec3_17ff70 {
    int x, y, z;
};
class Obj_17ff70 {
  public:
    char pad[0x30];
    Vec3_17ff70 v;
    bool Set(Vec3_17ff70* p);
};


// 0x0017ff70 FUN_0017ff70 (26 B): matches/0x0017ff70.cpp
// sym: ?Set@Obj_17ff70@fn_fa661594@@QAE_NPAUVec3_17ff70@2@@Z
bool Obj_17ff70::Set(Vec3_17ff70* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}

} // namespace fn_fa661594
