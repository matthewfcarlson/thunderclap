// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00357aa0 @ 0x00357aa0
struct Vec3 {
    float x, y, z;
};

struct Mat4 {
    float m[4][4];
    void FUN_0022c2b0(Vec3 *in, Vec3 *out);
};

struct Frame {
    Vec3 d;
    Vec3 out;
    Mat4 mat;
};

// Is point `pt` (relative to `origin`), expressed in the basis (ax, ay, az), inside the box `half`?
bool FUN_00357aa0(Vec3 *origin, Vec3 *half, Vec3 *ax, Vec3 *ay, Vec3 *az, Vec3 *pt)
{
    Frame f;
    f.d.x = pt->x - origin->x;
    f.d.y = pt->y - origin->y;
    f.d.z = pt->z - origin->z;

    f.mat.m[0][0] = ax->x;
    f.mat.m[0][1] = ay->x;
    f.mat.m[0][2] = az->x;
    f.mat.m[0][3] = 0;
    f.mat.m[1][0] = ax->y;
    f.mat.m[1][1] = ay->y;
    f.mat.m[1][2] = az->y;
    f.mat.m[1][3] = 0;
    f.mat.m[2][0] = ax->z;
    f.mat.m[2][1] = ay->z;
    f.mat.m[2][2] = az->z;
    f.mat.m[2][3] = 0;
    f.mat.m[3][0] = 0;
    f.mat.m[3][1] = 0;
    f.mat.m[3][2] = 0;
    f.mat.m[3][3] = 1.0f;

    f.mat.FUN_0022c2b0(&f.d, &f.out);

    if (-half->x > f.out.x) return false;
    if (half->x < f.out.x) return false;
    if (-half->y > f.out.y) return false;
    if (half->y < f.out.y) return false;
    if (-half->z > f.out.z) return false;
    if (half->z < f.out.z) return false;
    return true;
}
