// STATUS: equivalent (tools/equiv.py --wine and MSVC level 3)
// (integ2, D78, argfill) FUN_000c9460(&input, input): the callee's out pointer is the function's own by-value parameter
// (the original's argument slot; clang's frame copy): the stub fills its whole sizeof on both sides.
// object 0x000c9720..0x000ca850 (kind game, layer game, confidence high), dominant class Overlay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd3ccc71 {
#define TREE_TU_END }
namespace fn_fd3ccc71 {} using namespace fn_fd3ccc71;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd3ccc71 {
struct Vec3_c9720 { float x,y,z; };
struct Vec2_c9720 { float x,y; };
struct Object {
 char pad0[0x38];
 float x,y;
 char pad1[0x210-0x40];
 float margin;
 Vec2_c9720* FUN_000c9460(Vec3_c9720* output, Vec3_c9720 input);
 void target(Vec3_c9720 input);
};
struct V3_c9810 {
    float x, y, z;
};
struct V2_c9810 {
    float x, y;
};
struct Mat4_c9810 {
    float m[16];
    void FUN_0022b980();
};
struct Planar {
    float x, y, z;
};
struct Body_c9810 {
    char pad0[0x10];
    void *f10;
    char FUN_00035550_dummy;
};
struct Probe_c9810 {
    void FUN_00035550(V3_c9810 *out);
    hulk_freg FUN_00035690();
};
struct WorldSub {
    Probe_c9810 *FUN_00024280(int a, int b);
};
struct Slots_c9810 {
    void FUN_001e5bc0(int handle);
    void FUN_001dd470(int handle, Mat4_c9810 *m, int z);
};
} // namespace fn_fd3ccc71
struct World {
    char pad0[0xc];
    Slots_c9810 *f0c;
    char pad10[0x20 - 0x10];
    WorldSub *f20;
};
namespace fn_fd3ccc71 {
struct Shot_c9810 {
    int id;                // 0
    V3_c9810 pos;                // 4
    V2_c9810 v10;                // 0x10
    Planar w;              // 0x18
    char pad24[0x28 - 0x24];
    int a28;
    int b2c;
    char pad30[0x3c - 0x30];
    char flag3c;
    char pad3d[3];
};
struct Fx_c9810 {
    int active;            // 0
    char pad4[0x18 - 4];
    float f18, f1c, f20;
    V3_c9810 euler;              // 0x24
    int handle;            // 0x30
    char pad34[4];
};
class Tracker_c9810 {
public:
    char pad0[0x10];
    void *f10;
    char pad14[0x20 - 0x14];
    char f20;
    char pad21[0x21c - 0x21];
    float f21c;
    float f220;
    char b224;
    char pad225[0x258 - 0x225];
    Shot_c9810 shots[0x80];
    Fx_c9810 fx[0x20];
    char b2958;
    char b2959;

    char FUN_000c8550(int idx, V3_c9810 *out);
    char FUN_000c8630(int idx, V3_c9810 *out);
    void FUN_000c9720(V3_c9810 v);
    V2_c9810 *FUN_000c9460(V2_c9810 *out, V3_c9810 v);
    void FUN_000c9100(int idx);
    void FUN_000c9810(float dt);
};
struct Frame_c9810 {
    union {
        V3_c9810 out;
        V2_c9810 ret;
        V3_c9810 euler;
    } u;                   // 0x10
    V3_c9810 tmp;                // 0x1c
    V3_c9810 p;                  // 0x28
    Mat4_c9810 mat;              // 0x34
};
class DynamicCaster_c9ba0 {
  public:
    virtual void cast_000c96e0(void*);
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(DynamicCaster_c9ba0*, __int64);
};
} // namespace fn_fd3ccc71
extern "C" __int64 FUN_0027b020(void*);

namespace fn_fd3ccc71 {

// 0x000c9720 FUN_000c9720 (189 B): equivalent/0x000c9720.cpp
// sym: ?target@Object@fn_fd3ccc71@@QAEXUVec3_c9720@2@@Z @e09560ed15cf @wcc9cbaa0c760
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000c9720 @ 0x000c9720
void Object::target(Vec3_c9720 input) {
 Vec2_c9720* result = FUN_000c9460(&input,input);
 double upper = 1.0f - (double)margin;
 x = result->x;
 y = result->y;
 if (!(x >= margin && upper >= x)) x = upper < x ? (float)upper : margin;
 if (!(y >= margin && upper >= y)) y = upper < y ? (float)upper : margin;
}


} // namespace (case end)
