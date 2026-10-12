// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 14/16, incomplete)
// FUN_002b8b30 @ 0x002b8b30
struct Mat4 {
    float m[16];
};

struct Range {
    float lo;
    float hi;
};

struct Vec3 {
    float x, y, z;
    void FUN_0022d260(Mat4 *m);
    bool FUN_0022d2b0(Vec3 *other, float eps);
    void FUN_0022d180();
};

// Cone falloff of the two local axes (bits 0 and 1 of flags) relative to the direction `axis`.
void FUN_002b8b30(float *out1, float *out2, int flags, Range *range1, Range *range2, Mat4 *m, Vec3 *axis)
{
    *out1 = 1.0f;
    *out2 = 1.0f;
    if (flags == 0)
        return;

    Vec3 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 1.0f;
    v.FUN_0022d260(m);
    if (axis->FUN_0022d2b0(&v, 1e-5f))
        return;

    double dot = (double)v.y * axis->y + (double)v.x * axis->x + (double)v.z * axis->z;
    double len2 = (double)v.z * v.z + (double)v.y * v.y + (double)v.x * v.x;
    double k = dot / len2;
    Vec3 w;
    w.x = (float)(v.x * k);
    w.y = (float)(v.y * k);
    w.z = (float)(v.z * k);

    for (int i = 0; i < 2; i++) {
        if (!(flags & (1 << i)))
            continue;

        Vec3 u;
        u.x = (float)i;
        u.y = (float)(1 - i);
        u.z = 0.0f;
        u.FUN_0022d260(m);

        double dotU = (double)u.y * axis->y + (double)u.x * axis->x + (double)u.z * axis->z;
        double lenU = (double)u.z * u.z + (double)u.y * u.y + (double)u.x * u.x;
        double kU = dotU / lenU;
        Vec3 x;
        float y1 = (float)(u.y * kU);
        float z1 = (float)(u.z * kU);
        x.x = (float)(u.x * kU + w.x);
        x.y = y1 + w.y;
        x.z = z1 + w.z;
        x.FUN_0022d180();

        double t = (double)x.z * v.z + (double)x.y * v.y + (double)x.x * v.x;
        float tf = (float)t;
        Range *range = i == 0 ? range1 : range2;
        float *out = i == 0 ? out1 : out2;
        if (t > range->lo)
            *out = 1.0f;
        else if (!(tf > range->hi))
            *out = 0.0f;
        else
            *out = 1.0f - (tf - range->lo) / (range->hi - range->lo);
    }
}
