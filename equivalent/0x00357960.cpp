// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00357960 @ 0x00357960
struct Vec3_357960 {
    float x, y, z;
};

bool __cdecl FUN_0022de70(const Vec3_357960* point, const Vec3_357960* direction, const Vec3_357960* planePoint, const Vec3_357960* normal, Vec3_357960* result, float* parameter);
bool __cdecl FUN_003577c0(const Vec3_357960* p, const Vec3_357960* v1, const Vec3_357960* v2, const Vec3_357960* v3, const Vec3_357960* n);

bool FUN_00357960(const Vec3_357960* origin, const Vec3_357960* dir, float reach, const Vec3_357960* p5, const Vec3_357960* p6, const Vec3_357960* p7, const Vec3_357960* n, float* dist, Vec3_357960* hit, Vec3_357960* outN)
{
    if (!FUN_0022de70(origin, dir, p5, n, hit, dist)) {
        return false;
    }
    if (*dist < 0.0f) {
        return false;
    }
    if (reach < *dist) {
        return false;
    }
    *outN = *n;
    return FUN_003577c0(hit, p5, p6, p7, n);
}
