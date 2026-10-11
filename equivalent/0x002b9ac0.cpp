// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002b9ac0 @ 0x002b9ac0
struct Mat4 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
    void FUN_0022ca90(Mat4 *a, Mat4 *b);
};

struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
    void FUN_0022d260(Mat4 *m);
};

float FUN_00018a20(float x);

class Box {
public:
    void FUN_002b8f60(Mat4 *a, Mat4 *b, Mat4 *c, Mat4 *d, float scale);
    void FUN_002b9ac0(Mat4 *a, Mat4 *c, Mat4 *b, Mat4 *d, float scale);
};

void Box::FUN_002b9ac0(Mat4 *a, Mat4 *c, Mat4 *b, Mat4 *d, float scale)
{
    Vec3 pa;
    Vec3 pb;
    Vec3 up;
    Vec3 fwd;
    Vec3 w;
    Mat4 rot;
    Mat4 comb;

    pb.x = d->m[12];
    pb.y = d->m[13];
    pb.z = d->m[14];
    pa.x = c->m[12];
    pa.y = c->m[13];
    pa.z = c->m[14];

    up.x = 1.0f;
    up.y = 0.0f;
    up.z = 0.0f;
    fwd.x = 0.0f;
    fwd.y = 0.0f;
    fwd.z = -1.0f;
    up.FUN_0022d260(c);
    fwd.FUN_0022d260(c);

    double dx = (double)pb.x - (double)pa.x;
    double dy = (double)pb.y - (double)pa.y;
    double dz = (double)pb.z - (double)pa.z;
    double dot1 = up.z * dz + up.y * dy + up.x * dx;
    float t1x = (float)(up.x * dot1);
    float t1y = (float)(up.y * dot1);
    float t1z = (float)(up.z * dot1);
    double dot2 = fwd.z * dz + fwd.y * dy + fwd.x * dx;
    float t2y = (float)(fwd.y * dot2);
    float t2z = (float)(fwd.z * dot2);
    w.x = (float)(fwd.x * dot2 + t1x);
    w.y = (float)(t2y + t1y);
    w.z = (float)(t2z + t1z);

    w.FUN_0022d180();
    rot.FUN_0022b980();

    double c1 = w.z * up.z + w.y * up.y + w.x * up.x;
    float c2 = (float)(w.z * fwd.z + w.y * fwd.y + w.x * fwd.x);
    float ang;
    if (c1 > 0.0)
        ang = -FUN_00018a20(c2);
    else
        ang = FUN_00018a20(c2);
    rot.FUN_0022ba70(ang);
    comb.FUN_0022ca90(&rot, c);
    FUN_002b8f60(a, &comb, b, d, scale);
}
