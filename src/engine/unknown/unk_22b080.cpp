// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022b080..0x0022b650 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/Render.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f85dfc3b {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f85dfc3b {} using namespace fn_f85dfc3b;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f85dfc3b {
struct V {
    float x, y, z, w;
};
struct C_22b610 {
    int dummy;
    void Target(hulk_intptr a, V* p);
};
extern "C" void __cdecl FUN_0022b080(float *, const float *, const float *);


// 0x0022b080 FUN_0022b080 (146 B): matches/0x0022b080.cpp
// sym: _FUN_0022b080
extern "C" void FUN_0022b080(float* o, const float* a, const float* b) {
    float x = a[3] * b[1] + b[3] * a[1] + a[2] * b[0] - b[2] * a[0];
    float y = a[3] * b[2] + a[0] * b[1] + a[2] * b[3] - b[0] * a[1];
    float w = a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2];
    float z = b[3] * a[0] + b[2] * a[1] + a[3] * b[0] - a[2] * b[1];
    o[0] = z;
    o[1] = x;
    o[2] = y;
    o[3] = w;
}

} // namespace fn_f85dfc3b

// 0x0022b120 FUN_0022b120 (78 B): matches/0x0022b120.cpp
// sym: ?FUN_0022b120@Vec4_22b120@owners@@QAEXXZ
void owners::Vec4_22b120::FUN_0022b120() {
    hulk_freg scale = 1.0f / (hulk_freg)sqrt(x * x + y * y + z * z + w * w);  // the listing's order (MSVC 7.1 reassociates; clang does not)
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
}


// 0x0022b170 FUN_0022b170 (48 B): matches/0x0022b170.cpp
// sym: ?FUN_0022b170@Vec4_22b170@owners@@QAEXMPAM@Z
void owners::Vec4_22b170::FUN_0022b170(float angle, float* v) {
    hulk_freg a = angle * 0.5f;
    hulk_freg s = (hulk_freg)sin((double)a);
    w = (hulk_freg)cos((double)a);
    x = s * v[0];
    y = s * v[1];
    z = s * v[2];
}


// 0x0022b1c0 FUN_0022b1c0 (38 B): matches/0x0022b1c0.cpp
// sym: ?FUN_0022b1c0@X_22b1c0@owners@@QAEXM@Z
void owners::X_22b1c0::FUN_0022b1c0(float x) {
    a = 0;
    c = 0;
    hulk_freg h = x * 0.5f;
    b = (hulk_freg)sin(h);
    d = (hulk_freg)cos(h);
}


// 0x0022b220 FUN_0022b220 (175 B): equivalent/0x0022b220.cpp
// sym: ?FUN_0022b220@Quaternion_22b220@owners@@QAEXMMM@Z @2da5c9c04a0f @w49691d1a97f8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022b220 @ 0x0022b220
void owners::Quaternion_22b220::FUN_0022b220(float a,float b,float c) {
 double sa=sin(a*0.5), sb=sin(b*0.5);
 float ca=(float)cos(a*0.5), cb=(float)cos(b*0.5);
 float sc=(float)sin(c*0.5), cc=(float)cos(c*0.5);
 float t=(float)(ca*sb), u=(float)(sb*sa);
 double v=sa*cb, k=cb*ca;
 x=(float)(v*cc-t*sc);
 y=(float)(v*sc+t*cc);
 z=(float)(k*sc-u*cc);
 w=(float)(k*cc+u*sc);
}


// 0x0022b370 FUN_0022b370 (349 B): equivalent/0x0022b370.cpp
// sym: ?FUN_0022b370@Quat_22b370@owners@@QAEXPBM@Z @caf240bc7f3f @w59d03cbf96c9
// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 8/10, incomplete)
// FUN_0022b370 @ 0x0022b370
// Rotation matrix (row-major 4x4) to quaternion; the result has its w negated.
// x87: the trace, the sums and the differences stay in registers (53 bits) until they are stored
void owners::Quat_22b370::FUN_0022b370(const float *m)
{
    int next[3];
    float q[4];
    next[0] = 1;
    next[1] = 2;
    next[2] = 0;

    hulk_freg trace = (hulk_freg)m[5] + m[0] + m[10];
    if (trace > 0.0f) {
        double s = sqrt((double)(trace + 1.0f));
        w = (float)(-0.5f * s);
        double inv = (s != 0.0f) ? 0.5f / s : s;
        x = (float)(((hulk_freg)m[9] - m[6]) * inv);
        y = (float)(((hulk_freg)m[2] - m[8]) * inv);
        z = (float)(((hulk_freg)m[4] - m[1]) * inv);
        return;
    }

    int i = 0;
    if (m[5] > m[0])
        i = 1;
    if (m[10] > m[i * 5])
        i = 2;
    int j = next[i];
    int k = next[j];

    double s = sqrt((double)((hulk_freg)m[i * 5] - ((hulk_freg)m[k * 5] + m[j * 5]) + 1.0f));
    q[i] = (float)(0.5f * s);
    double inv = (s != 0.0f) ? 0.5f / s : s;
    q[3] = (float)(((hulk_freg)m[j + 4 * k] - m[k + 4 * j]) * inv);
    q[j] = (float)(((hulk_freg)m[i + 4 * j] + m[j + 4 * i]) * inv);
    q[k] = (float)(((hulk_freg)m[i + 4 * k] + m[k + 4 * i]) * inv);
    x = q[0];
    y = q[1];
    z = q[2];
    w = -q[3];
}


// 0x0022b4d0 FUN_0022b4d0 (134 B): equivalent/0x0022b4d0.cpp [wrapped: code differs from its standalone build]
// sym: ?Rotate@Quat_22b4d0@fn_0022b4d0@@QAEXPBUVec3_22b4d0@2@PAU32@@Z @0c5aa63cfb15 @w2a11f4b02165
namespace fn_0022b4d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022b4d0 @ 0x0022b4d0
struct Vec3_22b4d0 {
    float x, y, z;
};

struct Quat_22b4d0 {
    float x, y, z, w;
    void Rotate(const Vec3_22b4d0 *v, Vec3_22b4d0 *out);
};

extern "C++" __declspec(nothrow) void __cdecl FUN_0022b080(float *, const float *, const float *);

void Quat_22b4d0::Rotate(const Vec3_22b4d0 *v, Vec3_22b4d0 *out)
{
    Quat_22b4d0 tmp;
    Quat_22b4d0 vec;
    vec.x = v->x;
    vec.y = v->y;
    vec.z = v->z;
    vec.w = 0;
    FUN_0022b080((float *)(Quat_22b4d0 *)(&tmp), (const float *)(const Quat_22b4d0 *)this, (const float *)(const Quat_22b4d0 *)(&vec));
    vec.x = -x;
    vec.y = -y;
    vec.z = -z;
    vec.w = w;
    FUN_0022b080((float *)(Quat_22b4d0 *)(&tmp), (const float *)(const Quat_22b4d0 *)(&tmp), (const float *)(const Quat_22b4d0 *)(&vec));
    out->x = tmp.x;
    out->y = tmp.y;
    out->z = tmp.z;
}
} // namespace fn_0022b4d0


// 0x0022b560 FUN_0022b560 (80 B): matches/0x0022b560.cpp
// sym: ?FUN_0022b560@Vec4_22b560@owners@@QAEPAU12@PAU12@@Z
// data: gZero_22b560 = DAT_00421a78
owners::Vec4_22b560* owners::Vec4_22b560::FUN_0022b560(owners::Vec4_22b560* b) {
    if (b->w * w + b->z * z + b->y * y + b->x * x < (*(double*)&DAT_00421a78)) {
        x = -x;
        y = -y;
        z = -z;
        w = -w;
    }
    return this;
}

namespace fn_f85dfc3b {

// 0x0022b610 FUN_0022b610 (61 B): matches/0x0022b610.cpp
// sym: ?Target@C_22b610@fn_f85dfc3b@@QAEXHPAUV@2@@Z
void C_22b610::Target(hulk_intptr a, V* p) {
    V q;
    q.x = -p->x;
    q.y = -p->y;
    q.z = -p->z;
    q.w = p->w;
    FUN_0022b080((float *)(C_22b610 *)this, (const float *)(hulk_uintptr)(int)a, (const float *)(V *)(&q));
}

} // namespace fn_f85dfc3b
