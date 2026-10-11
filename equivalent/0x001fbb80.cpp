// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 9/10, incomplete)
// FUN_001fbb80 @ 0x001fbb80
struct V3 { float x, y, z; };

float __cdecl FUN_0004af40(float lo, float hi, float v);

class Bounds {
public:
    char pad0[0xb0];
    V3 min;
    V3 max;
    float angle;
    unsigned char sideFlags;
    void FUN_001fbb80(V3 *a, V3 *b, float rawAngle);
};

void Bounds::FUN_001fbb80(V3 *a, V3 *b, float rawAngle)
{
    float r = FUN_0004af40(0.0f, 6.2831855f, rawAngle);
    float ar = r < 0.0f ? -r : r;
    float v;
    if (ar <= 1e-5f) {
        v = 0.0f;
    } else {
        float w = r - 6.2831855f;
        if (w < 0.0f)
            w = -w;
        if (w <= 1e-5f)
            v = 0.0f;
        else
            v = r;
    }

    V3 lo = *a;
    V3 hi = *b;
    sideFlags = 0xff;
    float minX, minY, minZ;
    if (a->x > b->x) {
        hi.x = a->x;
        minX = b->x;
        sideFlags &= 0xfe;
    } else {
        minX = lo.x;
    }
    if (a->y > b->y) {
        hi.y = a->y;
        minY = b->y;
        sideFlags &= 0xfd;
    } else {
        minY = lo.y;
    }
    float maxZ;
    if (a->z > b->z) {
        minZ = b->z;
        maxZ = a->z;
        sideFlags &= 0xfb;
    } else {
        minZ = lo.z;
        maxZ = hi.z;
    }
    min.x = minX;
    min.y = minY;
    min.z = minZ;
    max.x = hi.x;
    max.y = hi.y;
    max.z = maxZ;
    angle = v;
}
