// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022baf0..0x00230800 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0022e180 FUN_0022e180 (99 B): matches/0x0022e180.cpp [isolated: macros; helper definitions (2 out-of-line function bodies); lost its match in the tree (call sequence differs)]
// sym: ?Set@Plane_22e180@fn_fcf80449@@QAEXPAUMat_22e180@2@PAUP4@2@@Z
#include "gen/owners.h"
namespace fn_fcf80449 {} using namespace fn_fcf80449;
namespace fn_fcf80449 {
struct V3_22e180 {
    float x, y, z;
};
struct Mat_22e180 {
    char pad[0x30];
    V3_22e180 t;
};
struct P4 {
    float x, y, z, w;
};
struct Plane_22e180 {
    float x, y, z, d;
    void Set(Mat_22e180* m, P4* p);
};
#if defined(__clang__)
void Plane_22e180::Set(Mat_22e180* m, P4* p) {
    ((owners::M_22c3b0 *)m)->FUN_0022c3b0((float *)p, (float *)this);
    hulk_freg f = -p->w;
    // x stays in an x87 register; y and z products are stored (rounded), their sums are not
    float py = f * y;
    float pz = f * z;
    hulk_freg sx = f * x + m->t.x;
    hulk_freg sy = py + m->t.y;
    hulk_freg sz = pz + m->t.z;
    d = -(sz * z + sy * y + sx * x);
}
#else
void Plane_22e180::Set(Mat_22e180* m, P4* p) {
    ((owners::M_22c3b0 *)m)->FUN_0022c3b0((float *)p, (float *)this);
    hulk_freg f = -p->w;
    V3_22e180 v;
    v.x = f * x;
    v.y = f * y;
    v.z = f * z;
    v.x += m->t.x;
    v.y += m->t.y;
    v.z += m->t.z;
    d = -((v.z) * z + v.y * y + v.x * x);
}
#endif
} // namespace fn_fcf80449

