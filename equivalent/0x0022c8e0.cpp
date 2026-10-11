// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0022c8e0 @ 0x0022c8e0
struct Vec3 { float x, y, z; };

struct Vec3N {
    float x, y, z;
    void FUN_0022d180();
};

struct Mat {
    float m[16];
    void LookAt(const Vec3 *center, const Vec3 *eye, const Vec3 *up);
};

void Mat::LookAt(const Vec3 *center, const Vec3 *eye, const Vec3 *up)
{
    Vec3N z;
    z.x = eye->x - center->x;
    z.y = eye->y - center->y;
    z.z = eye->z - center->z;
    z.FUN_0022d180();

    Vec3 s;
    s.x = z.z * up->y - z.y * up->z;
    s.y = z.x * up->z - z.z * up->x;
    s.z = z.y * up->x - z.x * up->y;

    Vec3 sc = s;
    Vec3 t;
    t.x = s.y * z.z - s.z * z.y;
    t.y = s.z * z.x - s.x * z.z;
    t.z = z.y * s.x - s.y * z.x;

    Vec3 tc = t;
    Vec3 zc;
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
