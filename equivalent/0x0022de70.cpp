// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0022de70 @ 0x0022de70
struct Vec3 { float x,y,z; };
bool __cdecl FUN_0022de70(const Vec3* point, const Vec3* direction, const Vec3* planePoint, const Vec3* normal, Vec3* result, float* parameter) {
    float planeDot = normal->z * planePoint->z + normal->y * planePoint->y + planePoint->x * normal->x;
    float denominator = direction->y * normal->y + direction->x * normal->x + normal->z * direction->z;
    union { float f; unsigned int u; } magnitude;
    magnitude.f = denominator; magnitude.u &= 0x7fffffff;
    if (!(magnitude.f < 1e-05f)) {
        float pointDot = point->z * normal->z + point->y * normal->y + point->x * normal->x;
        float t = (planeDot - pointDot) * (1.0f / denominator);
        *parameter = t;
        float x = t * direction->x;
        volatile float y = t * direction->y;
        volatile float z = t * direction->z;
        float rx = x + point->x;
        float ry = y + point->y;
        float rz = z + point->z;
        result->x = rx; result->y = ry; result->z = rz;
        return true;
    }
    float t = (point->z - planePoint->z) * normal->z + (point->x - planePoint->x) * normal->x + (point->y - planePoint->y) * normal->y;
    *parameter = t;
    float x = t * normal->x;
    volatile float y = t * normal->y;
    volatile float z = t * normal->z;
    float rx = point->x - x;
    float ry = point->y - y;
    float rz = point->z - z;
    result->x = rx; result->y = ry; result->z = rz;
    return false;
}
