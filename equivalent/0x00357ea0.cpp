// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00357ea0 @ 0x00357ea0
struct Vec3_357ea0 { float x, y, z; };
struct Frame_357ea0 {
    float d0, d1, d2;
    Vec3_357ea0 t0, t1, t2;
};
void FUN_001fd640(const Vec3_357ea0 *p, const Vec3_357ea0 *a, const Vec3_357ea0 *b, Vec3_357ea0 *closest);

void FUN_00357ea0(const Vec3_357ea0 *p, const Vec3_357ea0 *a, const Vec3_357ea0 *b, const Vec3_357ea0 *c, Vec3_357ea0 *out,
                  bool testAB, bool testBC, bool testCA)
{
    Frame_357ea0 f;
    f.d0 = 3.4028235e38f;
    f.d1 = 3.4028235e38f;
    f.d2 = 3.4028235e38f;
    if (testAB) {
        FUN_001fd640(p, a, b, &f.t0);
        float dx = f.t0.x - p->x;
        float dy = f.t0.y - p->y;
        float dz = f.t0.z - p->z;
        f.d0 = dz * dz + dy * dy + dx * dx;
    }
    if (testBC) {
        FUN_001fd640(p, b, c, &f.t1);
        float dx = f.t1.x - p->x;
        float dy = f.t1.y - p->y;
        float dz = f.t1.z - p->z;
        f.d1 = dz * dz + dy * dy + dx * dx;
    }
    if (testCA) {
        FUN_001fd640(p, c, a, &f.t2);
        float dx = f.t2.x - p->x;
        float dy = f.t2.y - p->y;
        float dz = f.t2.z - p->z;
        f.d2 = dz * dz + dy * dy + dx * dx;
    }
    if (f.d0 <= f.d1 && f.d0 <= f.d2) {
        *out = f.t0;
    } else if (f.d1 <= f.d2) {
        *out = f.t1;
    } else {
        *out = f.t2;
    }
}
