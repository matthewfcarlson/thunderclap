// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002b98d0 @ 0x002b98d0
struct Mat4_2b98d0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba30(float angle);
    void FUN_0022ca90(Mat4_2b98d0 *a, Mat4_2b98d0 *b);
};

struct Vec3_2b98d0 {
    float x, y, z;
    void FUN_0022d180();
    void FUN_0022d260(Mat4_2b98d0 *m);
};

float FUN_00018a20(float x);

class Box_2b98d0 {
public:
    void FUN_002b8f60(Mat4_2b98d0 *a, Mat4_2b98d0 *b, Mat4_2b98d0 *c, Mat4_2b98d0 *d, float scale);
    void FUN_002b98d0(Mat4_2b98d0 *a, Mat4_2b98d0 *c, Mat4_2b98d0 *b, Mat4_2b98d0 *d, float scale);
};

void Box_2b98d0::FUN_002b98d0(Mat4_2b98d0 *a, Mat4_2b98d0 *c, Mat4_2b98d0 *b, Mat4_2b98d0 *d, float scale)
{
    Vec3_2b98d0 pa;
    Vec3_2b98d0 pb;
    Vec3_2b98d0 up;
    Vec3_2b98d0 fwd;
    Vec3_2b98d0 w;
    Mat4_2b98d0 rot;
    Mat4_2b98d0 comb;

    pb.x = d->m[12];
    pb.y = d->m[13];
    pb.z = d->m[14];
    pa.x = c->m[12];
    pa.y = c->m[13];
    pa.z = c->m[14];

    up.x = 0.0f;
    up.y = 1.0f;
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
        ang = FUN_00018a20(c2);
    else
        ang = -FUN_00018a20(c2);
    rot.FUN_0022ba30(ang);
    comb.FUN_0022ca90(&rot, c);
    FUN_002b8f60(a, &comb, b, d, scale);
}
