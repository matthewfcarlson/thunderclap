// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00357960 @ 0x00357960
struct Vec3_357960 {
    float x, y, z;
};

bool __cdecl FUN_0022de70(const Vec3_357960* point, const Vec3_357960* direction, const Vec3_357960* planePoint, const Vec3_357960* normal, Vec3_357960* result, float* parameter);
extern "C" bool __cdecl FUN_003577c0(const void *, const void *, const void *, const void *, const void *);

extern "C" bool FUN_00357960(const void * origin, const void * dir, float reach, const void * p5, const void * p6, const void * p7, const void * n, float* dist, void * hit, void * outN_)
{
    Vec3_357960 * outN = (Vec3_357960 *)outN_;
    if (!FUN_0022de70(((const Vec3_357960 *)origin), ((const Vec3_357960 *)dir), ((const Vec3_357960 *)p5), ((const Vec3_357960 *)n), ((Vec3_357960 *)hit), dist)) {
        return false;
    }
    if (*dist < 0.0f) {
        return false;
    }
    if (reach < *dist) {
        return false;
    }
    *outN = *((const Vec3_357960 *)n);
    return FUN_003577c0((const Vec3_357960 *)((Vec3_357960 *)hit), (const Vec3_357960 *)((const Vec3_357960 *)p5), (const Vec3_357960 *)((const Vec3_357960 *)p6), (const Vec3_357960 *)((const Vec3_357960 *)p7), (const Vec3_357960 *)((const Vec3_357960 *)n));
}
