// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_002fae50 @ 0x002fae50
struct Vec3_2fae50 { float x, y, z; };

struct Triangle_2fae50 {
    Vec3_2fae50 a;
    Vec3_2fae50 b;
    Vec3_2fae50 c;
};

// Moeller-Trumbore ray / triangle test; *outT receives the hit distance.
// volatile floats are values the original spills to the stack (rounded to 32 bits); doubles are values it
// keeps in x87 registers.
bool FUN_002fae50(const Triangle_2fae50 *tri, const Vec3_2fae50 *origin, const Vec3_2fae50 *dir, float *outT)
{
    volatile float e1x = tri->b.x - tri->a.x;
    volatile float e1y = tri->b.y - tri->a.y;
    volatile float e1z = tri->b.z - tri->a.z;
    volatile float e2x = tri->c.x - tri->a.x;
    volatile float e2y = tri->c.y - tri->a.y;
    volatile float e2z = tri->c.z - tri->a.z;

    double px = (double)e2z * dir->y - (double)e2y * dir->z;
    double py = (double)e2x * dir->z - (double)e2z * dir->x;
    double pz = (double)e2y * dir->x - (double)e2x * dir->y;

    double detx = (double)e1z * pz;
    detx = detx + (double)e1y * py;
    detx = detx + (double)e1x * px;
    volatile float det = (float)detx;
    if (detx < 1e-5f)
        return false;

    volatile float sx = origin->x - tri->a.x;
    volatile float sy = origin->y - tri->a.y;
    double szx = (double)origin->z - tri->a.z;
    volatile float sz = (float)szx;

    double ud = szx * pz;
    ud = ud + (double)sy * py;
    ud = ud + (double)sx * px;
    volatile float u = (float)ud;
    if (u < 0.0f)
        return false;
    if (u > det)
        return false;

    volatile float qx = sy * e1z - sz * e1y;
    volatile float qy = sz * e1x - e1z * sx;
    double qzx = (double)sx * e1y - (double)sy * e1x;
    volatile float qz = (float)qzx;

    double v = qzx * dir->z;
    v = v + (double)qx * dir->x;
    v = v + (double)qy * dir->y;
    if (v < 0.0f)
        return false;
    if ((double)u + v > det)
        return false;

    double t = (double)qz * e2z;
    t = t + (double)qy * e2y;
    t = t + (double)qx * e2x;
    *outT = (float)(t / det);
    return true;
}
