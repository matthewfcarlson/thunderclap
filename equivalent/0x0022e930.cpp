// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0022e930 @ 0x0022e930
struct V3_22e930 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct Vec4_22e930 {
    unsigned int w[4];
    void FUN_002306c0(const Matrix* mat);
};

class Segment_22e930 {
public:
    unsigned int m[4][4];
    Vec4_22e930 pos;
    Vec4_22e930 a;
    Vec4_22e930 b;
    Vec4_22e930 c;
    V3_22e930* FUN_0022e930(V3_22e930* out, unsigned int n);
};

V3_22e930* Segment_22e930::FUN_0022e930(V3_22e930* out, unsigned int n)
{
    double inv = 1.0f / (double)n;
    a.w[0] = m[3][0];
    a.w[1] = m[2][0];
    a.w[2] = m[1][0];
    a.w[3] = m[0][0];
    b.w[0] = m[3][1];
    b.w[1] = m[2][1];
    b.w[2] = m[1][1];
    b.w[3] = m[0][1];
    c.w[0] = m[3][2];
    c.w[1] = m[2][2];
    c.w[2] = m[1][2];
    c.w[3] = m[0][2];
    Matrix d;
    double inv2 = inv * inv;
    double inv3 = inv2 * inv;
    d.m[0] = 0.0f;
    d.m[1] = (float)inv3;
    d.m[2] = (float)(inv3 * 6.0f);
    d.m[3] = (float)(inv3 * 6.0f);
    d.m[4] = 0.0f;
    d.m[5] = (float)inv2;
    d.m[6] = (float)(inv2 + inv2);
    d.m[7] = 0.0f;
    d.m[8] = 0.0f;
    d.m[9] = (float)inv;
    d.m[10] = 0.0f;
    d.m[11] = 0.0f;
    d.m[12] = 1.0f;
    d.m[13] = 0.0f;
    d.m[14] = 0.0f;
    d.m[15] = 0.0f;
    pos.w[0] = a.w[3];
    pos.w[1] = b.w[3];
    pos.w[2] = c.w[3];
    ((float*)pos.w)[3] = 1.0f;
    a.FUN_002306c0(&d);
    b.FUN_002306c0(&d);
    c.FUN_002306c0(&d);
    ((unsigned int*)out)[0] = pos.w[0];
    ((unsigned int*)out)[1] = pos.w[1];
    ((unsigned int*)out)[2] = pos.w[2];
    return out;
}
