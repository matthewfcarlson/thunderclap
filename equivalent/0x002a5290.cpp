// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 18/18; --wine 73 inputs)
// FUN_002a5290 @ 0x002a5290
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"

extern "C" double fmod(double x, double y);


struct Vec3_2a5290 { float x, y, z; };
struct Vec2_2a5290 { float x, y; };

struct Track {
    char pad0[0xc];
    int count;
    char pad10[8];
    Vec3_2a5290 *pos;
    char pad1c[0x1c];
    Vec2_2a5290 *uv[4];
};

extern "C" void FUN_002a5290(float t, void *a, void *b, unsigned int flags, float *c)
{
    Vec2_2a5290 *srcUv[4];
    Vec2_2a5290 *dstUv[4];
    srcUv[0] = ((Track *)a)->uv[0];
    dstUv[0] = ((Track *)b)->uv[0];
    srcUv[1] = ((Track *)a)->uv[1];
    dstUv[1] = ((Track *)b)->uv[1];
    srcUv[2] = ((Track *)a)->uv[2];
    dstUv[2] = ((Track *)b)->uv[2];
    srcUv[3] = ((Track *)a)->uv[3];
    dstUv[3] = ((Track *)b)->uv[3];
    Vec3_2a5290 *srcPos = ((Track *)a)->pos;
    Vec3_2a5290 *dstPos = ((Track *)b)->pos;
    int n = ((Track *)a)->count;
    if (n == 0)
        return;
    unsigned int moveFlag = flags & 0x10;
    do {
        n--;
        if (moveFlag != 0) {
            dstPos[n].x = srcPos[n].x + t * c[0] * c[2];
            dstPos[n].y = srcPos[n].y + t * c[0] * c[3];
            dstPos[n].z = srcPos[n].z + t * c[0] * c[4];
        }
        for (int i = 0; i < 4; i++) {
            if ((((unsigned int*)&DAT_0042d9c0)[i] & flags) == 0)
                continue;
            if (srcUv[i] == 0)
                continue;
            if (dstUv[i] == 0)
                continue;
            hulk_freg uu = t * c[1];   // `fst [temp]`: the first fmod gets the register, the second the stored float
            float ur = (float)uu;
            float f1 = (float)fmod(uu * c[5], 1.0);
            hulk_freg f2 = fmod(ur * c[6], 1.0);
            hulk_freg g1 = f1;
            if (f1 < 0.0)
                g1 = 1.0f - f1;
            if (f2 < 0.0)
                f2 = 1.0f - f2;
            dstUv[i][n].x = g1 + srcUv[i][n].x;
            dstUv[i][n].y = f2 + srcUv[i][n].y;
        }
    } while (n != 0);
}
