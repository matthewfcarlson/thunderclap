// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 2/2)
// FUN_0022cdb0 @ 0x0022cdb0
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

struct Matrix {
    float m[16];
    void FUN_0022c120();
    void FUN_0022cdb0();
};

void Matrix::FUN_0022cdb0()
{
    float t[16];
    volatile float p1 = m[6] * m[8];
    volatile float p2 = m[9] * m[4];
    volatile float p3 = m[5] * m[8];
    volatile float p4 = m[4] * m[10];
    volatile float p5 = m[6] * m[9];
    float det = m[5] * m[10] * m[0];
    det = det + p1 * m[1];
    det = det + p2 * m[2];
    float n3 = -(p3 * m[2]);
    det = det + n3;
    float n4 = -(p4 * m[1]);
    det = det + n4;
    float n5 = -(p5 * m[0]);
    det = det + n5;
    union {
        float f;
        unsigned int u;
    } d;
    d.f = det - 1.0f;
    d.u &= 0x7fffffff;
    if (d.f <= 0.00001f) {
        FUN_0022c120();
        return;
    }
    float r = 1.0f / det;
    t[0] = (m[5] * m[10] - p5) * r;
    t[4] = -((p4 - p1) * r);
    t[8] = (p2 - p3) * r;
    t[1] = -((m[1] * m[10] - m[9] * m[2]) * r);
    t[5] = (m[0] * m[10] - m[2] * m[8]) * r;
    t[9] = -((m[9] * m[0] - m[1] * m[8]) * r);
    t[2] = (m[6] * m[1] - m[5] * m[2]) * r;
    t[6] = -((m[6] * m[0] - m[4] * m[2]) * r);
    t[15] = m[15];
    t[10] = (m[5] * m[0] - m[1] * m[4]) * r;
    t[12] = -(t[0] * m[12] + t[4] * m[13] + t[8] * m[14]);
    t[13] = -(t[1] * m[12] + t[5] * m[13] + t[9] * m[14]);
    t[14] = -(t[2] * m[12] + t[6] * m[13] + t[10] * m[14]);
    memcpy(m, t, 64);
    m[11] = 0.0f;
    m[7] = 0.0f;
    m[3] = 0.0f;
    m[15] = 1.0f;
}
