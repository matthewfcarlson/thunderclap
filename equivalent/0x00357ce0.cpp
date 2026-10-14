// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00357ce0 @ 0x00357ce0
struct Vec3_357ce0 {
    float x, y, z;
};

void __cdecl FUN_001fd640(const Vec3_357ce0 *p, const Vec3_357ce0 *a, const Vec3_357ce0 *b, Vec3_357ce0 *closest);

static const float FLT_MAX_ = 3.4028235e+38f;

static float DistSq(const Vec3_357ce0 &q, const Vec3_357ce0 *p)
{
    float dx = q.x - p->x;
    float dy = q.y - p->y;
    float dz = q.z - p->z;
    return dz * dz + dy * dy + dx * dx;
}

void FUN_00357ce0(const Vec3_357ce0 *p, const Vec3_357ce0 *a, const Vec3_357ce0 *b, const Vec3_357ce0 *c,
                  Vec3_357ce0 *outFrom, Vec3_357ce0 *outTo, bool testAB, bool testBC, bool testCA)
{
    struct Frame {
        float dist0;
        float pad;
        float dist1;
        Vec3_357ce0 qAB;
        Vec3_357ce0 qBC;
        Vec3_357ce0 qCA;
    } f;
    f.dist0 = FLT_MAX_;
    f.dist1 = FLT_MAX_;
    if (testAB) {
        FUN_001fd640(p, a, b, &f.qAB);
        f.dist0 = DistSq(f.qAB, p);
    }
    if (testBC) {
        FUN_001fd640(p, b, c, &f.qBC);
        // the original measures qAB here (a stale buffer, even when testAB was false), not qBC
        f.dist0 = DistSq(f.qAB, p);
    }
    if (testCA) {
        FUN_001fd640(p, c, a, &f.qCA);
        f.dist1 = DistSq(f.qCA, p);
    }
    if (f.dist0 <= FLT_MAX_ && f.dist0 <= f.dist1) {
        *outFrom = *a;
        *outTo = *b;
    } else if (FLT_MAX_ <= f.dist1) {
        *outFrom = *b;
        *outTo = *c;
    } else {
        *outFrom = *c;
        *outTo = *a;
    }
}
