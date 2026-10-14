// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 6/6)
// FUN_002f05f0 @ 0x002f05f0
struct Vec3_2f05f0 {
    float x, y, z;
    float FUN_0022d110();
};

union Slot_2f05f0 {
    const Vec3_2f05f0 *ptr;
    float f;
};

char FUN_002f0080(Vec3_2f05f0 *p, Vec3_2f05f0 *q, Vec3_2f05f0 *extent);
char FUN_002f04c0(Vec3_2f05f0 *p, Vec3_2f05f0 *dir, float len, float radius, float *t);

// Segment p -> q (both relative to origin) swept with a margin of (r0 + r1);
// on a hit writes the world-space hit point to out.  The origin slot is reused
// as scratch for the hit parameter, and r0/r1 as scratch for radius/length.
bool FUN_002f05f0(Vec3_2f05f0 p, Vec3_2f05f0 q, Slot_2f05f0 origin, float r0, float r1, Vec3_2f05f0 *out)
{
    const Vec3_2f05f0 *o = origin.ptr;
    Vec3_2f05f0 dir;

    p.x = p.x - o->x;
    p.y = p.y - o->y;
    p.z = p.z - o->z;
    q.x = q.x - o->x;
    q.y = q.y - o->y;
    q.z = q.z - o->z;

    float r = r0 + r1;
    dir.x = r;
    dir.y = r;
    dir.z = r;
    r0 = r;
    origin.f = r;
    if (FUN_002f0080(&p, &q, &dir))
        return false;

    dir.x = q.x - p.x;
    dir.y = q.y - p.y;
    dir.z = q.z - p.z;
    r1 = dir.FUN_0022d110();
    if (!FUN_002f04c0(&p, &dir, r1, r0, &origin.f))
        return false;

    if (out) {
        out->x = p.x + o->x;
        out->y = p.y + o->y;
        out->z = p.z + o->z;
        out->x = dir.x * origin.f + out->x;
        out->y = dir.y * origin.f + out->y;
        out->z = dir.z * origin.f + out->z;
    }
    return true;
}
