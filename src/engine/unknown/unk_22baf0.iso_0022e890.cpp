// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022baf0..0x00230800 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x0022e890 FUN_0022e890 (157 B): equivalent/0x0022e890.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_0022e890@Segment_22e890@fn_fc701bfd@@QAEXPAUV3_22e890@2@M@Z
#include "gen/owners.h"
namespace fn_fc701bfd {} using namespace fn_fc701bfd;
namespace fn_fc701bfd {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022e890 @ 0x0022e890
// Segment::FUN_0022e890 @ 0x0022e890: evaluate the cubic segment at t (clamped to [0,1])
struct V3_22e890 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct Vec4_22e890 {
    float x, y, z, w;
};

class Segment_22e890 {
public:
    float m[16];
    Vec4_22e890 pos;
    void FUN_0022e890(V3_22e890 *out, float t);
};

void Segment_22e890::FUN_0022e890(V3_22e890 *out, float t)
{
    if (!(t >= 0.0f))
        t = 0.0f;
    else if (t > 1.0f)
        t = 1.0f;

    pos.x = 1.0f;
    pos.y = t;
    pos.z = t * t;
    pos.w = t * t * t;
    ((owners::Obj_2306c0 *)&pos)->FUN_002306c0((hulk_intptr)(const Matrix *)((const Matrix *)this));

    out->x = pos.x;
    out->y = pos.y;
    out->z = pos.z;
}
} // namespace fn_fc701bfd

