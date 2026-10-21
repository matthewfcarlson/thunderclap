// STATUS: equivalent (tools/equiv.py level 3: 19780 inputs, branch coverage 2/2)
// FUN_002bdaf0 @ 0x002bdaf0
#include "compat/ptr.h"

struct QuadVertex {
    float x, y, z;
    int color;
    float u, v;
};

struct Quad_2bdaf0 {
    QuadVertex v[4];
};

struct RectInts {
    int i0;
    int i4;
    int i8;
    int ic;
    int i10;
    int i14;
};


class QuadBatch {
public:
    char pad00[0x44];
    Quad_2bdaf0 *quads;          // 0x44
    char pad48[0x54 - 0x48];
    int height;           // 0x54
    char pad58[0x5c - 0x58];
    int border;           // 0x5c
    char pad60[0x70 - 0x60];
    float scaleX;         // 0x70
    float scaleY;         // 0x74
    char pad78[0xa0 - 0x78];
    unsigned char noBorder; // 0xa0

    void FUN_002bdaf0(int index, const RectInts *r, int w, int h);
};

void QuadBatch::FUN_002bdaf0(int index, const RectInts *r, int w, int h)
{
    // x87 (docs/native-float.md): the int->float conversions are exact in the register; W, H, bf, Q, R and bottomV
    // go through float frame slots (rounded), the texture coordinates s0..s2 stay in registers until stored.
    hulk_freg s0, s1, s2;
    float bottomV;
    if (noBorder) {
        s0 = 0.0f;
        s1 = r->i14;
        s2 = 0.0f;
        bottomV = (float)r->i10;
    } else {
        int borderI = border;
        int right = r->i14 + borderI;
        int bottom = r->i10 + borderI;
        volatile float W = (float)w;   // volatile: MSVC 7.1 turns two divisions by W (or H) into a reciprocal multiply
        float Q = (float)(1.0 / ((double)w + w));
        volatile float H = (float)h;
        float R = (float)(1.0 / ((double)h * 4.0f));
        float bf = (float)borderI;
        s2 = (double)borderI / W + Q;
        s1 = (double)right / W + Q;
        bottomV = (float)(1.0 - bf / H - R);
        s0 = 1.0 - (double)bottom / H - R;
    }

    quads[index].v[0].color = -1;
    quads[index].v[1].color = -1;
    quads[index].v[2].color = -1;
    quads[index].v[3].color = -1;

    QuadVertex *v;
    float x, y;

    v = &quads[index].v[0];
    y = (float)(height - r->i8) * scaleY;
    x = (float)r->ic * scaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[0].u = s1;
    quads[index].v[0].v = s0;

    v = &quads[index].v[1];
    y = (float)(height - r->i8) * scaleY;
    x = (float)r->i4 * scaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[1].u = s2;
    quads[index].v[1].v = s0;

    v = &quads[index].v[2];
    y = (float)(height - r->i0) * scaleY;
    x = (float)r->ic * scaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[2].u = s1;
    quads[index].v[2].v = bottomV;

    v = &quads[index].v[3];
    y = (float)(height - r->i0) * scaleY;
    x = (float)r->i4 * scaleX;
    v->z = 0;
    v->x = x;
    v->y = y;
    quads[index].v[3].u = s2;
    quads[index].v[3].v = bottomV;
}
