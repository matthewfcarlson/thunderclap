// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/10, incomplete)
// FUN_002fae50 @ 0x002fae50
struct Vec3 { float x, y, z; };

struct Triangle {
    Vec3 a;
    Vec3 b;
    Vec3 c;
};

// Moeller-Trumbore ray / triangle test; *outT receives the hit distance.
bool FUN_002fae50(const Triangle *tri, const Vec3 *origin, const Vec3 *dir, float *outT)
{
    Vec3 e1, e2;
    e1.x = tri->b.x - tri->a.x;
    e1.y = tri->b.y - tri->a.y;
    e1.z = tri->b.z - tri->a.z;
    e2.x = tri->c.x - tri->a.x;
    e2.y = tri->c.y - tri->a.y;
    e2.z = tri->c.z - tri->a.z;

    Vec3 p;
    p.x = e2.z * dir->y - e2.y * dir->z;
    p.y = e2.x * dir->z - e2.z * dir->x;
    p.z = e2.y * dir->x - e2.x * dir->y;

    float det = e1.z * p.z + e1.y * p.y + e1.x * p.x;
    if (det < 1e-5f)
        return false;

    Vec3 s;
    s.x = origin->x - tri->a.x;
    s.y = origin->y - tri->a.y;
    s.z = origin->z - tri->a.z;

    float u = s.z * p.z + s.y * p.y + s.x * p.x;
    if (u < 0.0f)
        return false;
    if (u > det)
        return false;

    Vec3 q;
    q.x = s.y * e1.z - s.z * e1.y;
    q.y = s.z * e1.x - e1.z * s.x;
    q.z = s.x * e1.y - s.y * e1.x;

    float v = q.z * dir->z + q.x * dir->x + q.y * dir->y;
    if (v < 0.0f)
        return false;
    if (u + v > det)
        return false;

    *outT = (q.z * e2.z + q.y * e2.y + q.x * e2.x) / det;
    return true;
}
