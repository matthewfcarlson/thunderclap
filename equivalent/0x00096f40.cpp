// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 7/8, incomplete)
// FUN_00096f40 @ 0x00096f40
struct Vec3_96f40 {
    float x, y, z;
};

struct Plane_96f40 {
    float nx, ny, nz, d;
    void FUN_0022dfe0(const Vec3_96f40 *a, const Vec3_96f40 *b, const Vec3_96f40 *c);
    char FUN_0022e1f0(const Vec3_96f40 *from, const Vec3_96f40 *to, float *t);
};

char FUN_00096f40(Vec3_96f40 v1, Vec3_96f40 v2, Vec3_96f40 v3, Vec3_96f40 v4)
{
    Plane_96f40 plane;
    float t;
    Vec3_96f40 up;
    up.x = v3.x;
    up.y = v3.y + 1.0f;
    up.z = v3.z;
    plane.FUN_0022dfe0(&v3, &up, &v4);
    if (!plane.FUN_0022e1f0(&v1, &v2, &t))
        return 0;

    Vec3_96f40 d;
    d.x = v2.x - v1.x;
    d.y = v2.y - v1.y;
    d.z = v2.z - v1.z;
    float dtx = d.x * t;
    float dty = d.y * t;
    float dtz = d.z * t;
    Vec3_96f40 q;
    q.x = v1.x + dtx;
    float qy = v1.y + dty;
    q.z = v1.z + dtz;
    if (qy < v3.y)
        return 0;

    float ex = v4.x - v3.x;
    float ey = v4.y - v3.y;
    float ez = v4.z - v3.z;
    float lenSq = ez * ez + ey * ey + ex * ex;

    float gx = q.x - v3.x;
    float gy = 0.0f;
    float gz = q.z - v3.z;
    Vec3_96f40 h;
    h.x = q.x - v4.x;
    h.y = v3.y - v4.y;
    h.z = q.z - v4.z;
    if (lenSq < gz * gz + gy * gy + gx * gx)
        return 0;
    if (lenSq < h.z * h.z + h.y * h.y + h.x * h.x)
        return 0;
    return 1;
}
