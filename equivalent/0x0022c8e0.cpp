// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 0/0; --wine 606 inputs)
// FUN_0022c8e0 @ 0x0022c8e0
#include "compat/ptr.h"
struct Vec3_22c8e0 { float x, y, z; };

struct Vec3N {
    float x, y, z;
    void FUN_0022d180();
};

struct Mat_22c8e0 {
    float m[16];
    void LookAt(const Vec3_22c8e0 *center, const Vec3_22c8e0 *eye, const Vec3_22c8e0 *up);
};

void Mat_22c8e0::LookAt(const Vec3_22c8e0 *center, const Vec3_22c8e0 *eye, const Vec3_22c8e0 *up)
{
    Vec3N z;
    z.x = eye->x - center->x;
    z.y = eye->y - center->y;
    z.z = eye->z - center->z;
    z.FUN_0022d180();

    Vec3_22c8e0 s;
    hulk_freg sxr = z.z * up->y - z.y * up->z;
    s.x = sxr;
    s.y = z.x * up->z - z.z * up->x;
    s.z = z.y * up->x - z.x * up->y;

    Vec3_22c8e0 sc = s;
    Vec3_22c8e0 t;
    t.x = s.y * z.z - s.z * z.y;
    t.y = s.z * z.x - sxr * z.z;
    t.z = z.y * sxr - s.y * z.x;

    Vec3_22c8e0 tc = t;
    Vec3_22c8e0 zc;
    zc.x = z.x;
    zc.y = z.y;
    zc.z = z.z;
    float a = sc.x * eye->x + sc.y * eye->y + sc.z * eye->z;
    float b = tc.x * eye->x + tc.y * eye->y + tc.z * eye->z;
    float c = zc.x * eye->x + zc.y * eye->y + zc.z * eye->z;

    m[1] = s.y;
    m[5] = t.y;
    m[2] = s.z;
    m[4] = t.x;
    m[9] = z.y;
    m[0] = s.x;
    m[3] = -a;
    m[6] = z.z;
    m[8] = z.x;
    m[7] = -b;
    m[10] = z.z;
    m[11] = -c;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}
