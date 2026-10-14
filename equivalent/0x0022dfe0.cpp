// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022dfe0 @ 0x0022dfe0
struct Vec3_22dfe0 {
    float x, y, z;
};

class Plane_22dfe0 {
public:
    Vec3_22dfe0 normal;
    float d;

    void FUN_0022d180();    // normalize
    void FUN_0022dfe0(const Vec3_22dfe0 *a, const Vec3_22dfe0 *b, const Vec3_22dfe0 *c);
};

// Plane through three points: normal = (b - a) x (c - a), d = -dot(a, normal).
void Plane_22dfe0::FUN_0022dfe0(const Vec3_22dfe0 *a, const Vec3_22dfe0 *b, const Vec3_22dfe0 *c)
{
    float ux = b->x - a->x;
    float uy = b->y - a->y;
    float uz = b->z - a->z;
    volatile float vx = c->x - a->x;
    volatile float vy = c->y - a->y;
    float vz = c->z - a->z;
    normal.x = vz * uy - vy * uz;
    normal.y = uz * vx - vz * ux;
    normal.z = vy * ux - vx * uy;
    FUN_0022d180();
    d = -(a->x * normal.x + a->z * normal.z + a->y * normal.y);
}
