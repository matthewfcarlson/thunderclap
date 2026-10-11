// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00298530 @ 0x00298530
struct Matrix3 { float r[3][4]; };
struct Box { float min[3]; float max[3]; void FUN_00298530(const Matrix3* m, const Box* src); };
struct Pt { float v[3]; void FUN_0022d210(const Matrix3* m); };

static inline float fabsf_(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}

void Box::FUN_00298530(const Matrix3* m, const Box* src)
{
    Pt c;
    float ext[3];
    float h[3];
    float p[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        c.v[i] = (src->max[i] + src->min[i]) * 0.5f;
    }
    for (i = 0; i < 3; i++) {
        h[i] = src->max[i] - c.v[i];
        for (j = 0; j < 3; j++) {
            p[i][j] = h[i] * m->r[i][j];
        }
    }
    for (j = 0; j < 3; j++) {
        ext[j] = (fabsf_(p[2][j]) + fabsf_(p[1][j])) + fabsf_(p[0][j]);
    }
    c.FUN_0022d210(m);
    max[0] = ext[0] + c.v[0];
    max[1] = ext[1] + c.v[1];
    max[2] = ext[2] + c.v[2];
    min[0] = c.v[0] - ext[0];
    min[1] = c.v[1] - ext[1];
    min[2] = c.v[2] - ext[2];
}
