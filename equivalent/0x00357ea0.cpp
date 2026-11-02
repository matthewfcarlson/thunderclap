// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00357ea0 @ 0x00357ea0
struct Vec3_357ea0 { float x, y, z; };
struct Frame_357ea0 {
    float d0, d1, d2;
    Vec3_357ea0 t0, t1, t2;
};
extern "C" void __cdecl FUN_001fd640(void *, void *, void *, void *);

extern "C" void FUN_00357ea0(const void *p, const void *a, const void *b, const void *c, void * out_,
                  bool testAB, bool testBC, bool testCA)
{
    Vec3_357ea0 * out = (Vec3_357ea0 *)out_;
    Frame_357ea0 f;
    f.d0 = 3.4028235e38f;
    f.d1 = 3.4028235e38f;
    f.d2 = 3.4028235e38f;
    if (testAB) {
        FUN_001fd640((void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)p), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)a), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)b), (Vec3_357ea0 *)(&f.t0));
        float dx = f.t0.x - ((const Vec3_357ea0 *)p)->x;
        float dy = f.t0.y - ((const Vec3_357ea0 *)p)->y;
        float dz = f.t0.z - ((const Vec3_357ea0 *)p)->z;
        f.d0 = dz * dz + dy * dy + dx * dx;
    }
    if (testBC) {
        FUN_001fd640((void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)p), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)b), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)c), (Vec3_357ea0 *)(&f.t1));
        float dx = f.t1.x - ((const Vec3_357ea0 *)p)->x;
        float dy = f.t1.y - ((const Vec3_357ea0 *)p)->y;
        float dz = f.t1.z - ((const Vec3_357ea0 *)p)->z;
        f.d1 = dz * dz + dy * dy + dx * dx;
    }
    if (testCA) {
        FUN_001fd640((void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)p), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)c), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)a), (Vec3_357ea0 *)(&f.t2));
        float dx = f.t2.x - ((const Vec3_357ea0 *)p)->x;
        float dy = f.t2.y - ((const Vec3_357ea0 *)p)->y;
        float dz = f.t2.z - ((const Vec3_357ea0 *)p)->z;
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
