// STATUS: equivalent (tools/equiv.py level 3: 42 inputs, branch coverage 18/18)
// FUN_002a5290 @ 0x002a5290
extern "C" double fmod(double x, double y);

extern unsigned int DAT_0042d9c0[4];

struct Vec3 { float x, y, z; };
struct Vec2 { float x, y; };

struct Track {
    char pad0[0xc];
    int count;
    char pad10[8];
    Vec3 *pos;
    char pad1c[0x1c];
    Vec2 *uv[4];
};

void FUN_002a5290(float t, Track *a, Track *b, unsigned int flags, float *c)
{
    Vec2 *srcUv[4];
    Vec2 *dstUv[4];
    srcUv[0] = a->uv[0];
    dstUv[0] = b->uv[0];
    srcUv[1] = a->uv[1];
    dstUv[1] = b->uv[1];
    srcUv[2] = a->uv[2];
    dstUv[2] = b->uv[2];
    srcUv[3] = a->uv[3];
    dstUv[3] = b->uv[3];
    Vec3 *srcPos = a->pos;
    Vec3 *dstPos = b->pos;
    int n = a->count;
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
            if ((DAT_0042d9c0[i] & flags) == 0)
                continue;
            if (srcUv[i] == 0)
                continue;
            if (dstUv[i] == 0)
                continue;
            float u = t * c[1];
            float f1 = (float)fmod(u * c[5], 1.0);
            float f2 = (float)fmod(u * c[6], 1.0);
            if (f1 < 0.0)
                f1 = 1.0f - f1;
            if (f2 < 0.0)
                f2 = 1.0f - f2;
            dstUv[i][n].x = f1 + srcUv[i][n].x;
            dstUv[i][n].y = f2 + srcUv[i][n].y;
        }
    } while (n != 0);
}
