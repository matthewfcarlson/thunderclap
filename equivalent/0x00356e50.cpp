// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00356e50 @ 0x00356e50
#include "decls/data/engine/pure3d.h"

struct Grad_356e50 {
    float x, y;
};


// 2D gradient (Perlin) noise at point p[0], p[1].
float __stdcall FUN_00356e50(const float *p)
{
    float xs = p[0] + 4096.0f;
    int xi = (int)xs;
    float fx = xs - (float)xi;
    int ix = xi & 0xff;
    float fx1 = fx - 1.0f;

    float ys = p[1] + 4096.0f;
    int yi = (int)ys;
    int iy = yi & 0xff;
    int a = DAT_0056bfc8[ix];
    float fy = ys - (float)yi;
    int iy1 = (iy + 1) & 0xff;
    int ix1 = (ix + 1) & 0xff;
    float fy1 = fy - 1.0f;
    int b = DAT_0056bfc8[ix1];

    float u = (3.0f - (fx + fx)) * fx * fx;

    const Grad_356e50 *g00 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[a + iy]];
    const Grad_356e50 *g10 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[iy + b]];
    const Grad_356e50 *g11 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[b + iy1]];
    const Grad_356e50 *g01 = &((Grad_356e50*)&DAT_0056dfe8)[DAT_0056bfc8[a + iy1]];

    float d00 = fy * g00->y + fx * g00->x;
    float d10 = fy * g10->y + fx1 * g10->x;
    float x0 = (d10 - d00) * u + d00;

    float d01 = fx * g01->x + fy1 * g01->y;
    float d11 = fy1 * g11->y + fx1 * g11->x;
    float x1 = d01 + (d11 - d01) * u;

    return (x1 - x0) * ((3.0f - (fy + fy)) * fy * fy) + x0;
}
