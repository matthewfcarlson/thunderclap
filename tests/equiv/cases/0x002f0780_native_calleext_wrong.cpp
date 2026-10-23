// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 8/8)
// FUN_002f0780 @ 0x002f0780
struct Vec3_2f0780 {
    float x, y, z;
};

char FUN_002f0080(Vec3_2f0780 *p, Vec3_2f0780 *q, Vec3_2f0780 *extent);
float FUN_002f0230(Vec3_2f0780 *p, Vec3_2f0780 *d, Vec3_2f0780 *extent);

// Segment p -> q (relative to origin) against a box grown by r; on a hit within the
// segment writes the world-space hit point to out.  The r slot is reused for the hit parameter.
bool FUN_002f0780(Vec3_2f0780 p, Vec3_2f0780 q, const Vec3_2f0780 *origin, Vec3_2f0780 box, float r, Vec3_2f0780 *out)
{
    Vec3_2f0780 d;

    p.x = p.x - origin->x;
    p.y = p.y - origin->y;
    p.z = p.z - origin->z;
    q.x = q.x - origin->x;
    q.y = q.y - origin->y;
    q.z = q.z - origin->z;
    box.x = box.x + r;
    box.y = box.y + r;
    box.z = box.z + r + r;   // WRONG: the box FUN_002f0080 and FUN_002f0230 read (12 bytes)
    if (FUN_002f0080(&p, &q, &box))
        return false;

    d.x = q.x - p.x;
    d.y = q.y - p.y;
    d.z = q.z - p.z;
    r = FUN_002f0230(&p, &d, &box);
    if (r < 0.0f)
        return false;
    if (!(r <= 1.0f))
        return false;

    if (out) {
        out->x = p.x + origin->x;
        out->y = p.y + origin->y;
        out->z = p.z + origin->z;
        out->x = d.x * r + out->x;
        out->y = d.y * r + out->y;
        out->z = d.z * r + out->z;
    }
    return true;
}
