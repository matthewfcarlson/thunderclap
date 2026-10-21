// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 2/2)
// FUN_0022de70 @ 0x0022de70
#include "compat/ptr.h"
struct Vec3_22de70 { float x,y,z; };
bool __cdecl FUN_0022de70(const Vec3_22de70* point, const Vec3_22de70* direction, const Vec3_22de70* planePoint, const Vec3_22de70* normal, Vec3_22de70* result, float* parameter) {
    hulk_freg planeDot = normal->z * planePoint->z + normal->y * planePoint->y + planePoint->x * normal->x;
    hulk_freg denominator = direction->y * normal->y + direction->x * normal->x + normal->z * direction->z;
    union { float f; unsigned int u; } magnitude;
    magnitude.f = denominator; magnitude.u &= 0x7fffffff;
    if (!(magnitude.f < 1e-05f)) {
        hulk_freg pointDot = point->z * normal->z + point->y * normal->y + point->x * normal->x;
        hulk_freg t = (planeDot - pointDot) * (1.0f / denominator);
        *parameter = t;
        hulk_freg x = t * direction->x;
        volatile float y = t * direction->y;
        volatile float z = t * direction->z;
        hulk_freg rx = x + point->x;
        hulk_freg ry = y + point->y;
        hulk_freg rz = z + point->z;
        result->x = rx; result->y = ry; result->z = rz;
        return true;
    }
    hulk_freg t = (point->z - planePoint->z) * normal->z + (point->x - planePoint->x) * normal->x + (point->y - planePoint->y) * normal->y;
    *parameter = t;
    hulk_freg x = t * normal->x;
    volatile float y = t * normal->y;
    volatile float z = t * normal->z;
    hulk_freg rx = point->x - x;
    hulk_freg ry = point->y - y;
    hulk_freg rz = point->z - z;
    result->x = rx; result->y = ry; result->z = rz;
    return false;
}
