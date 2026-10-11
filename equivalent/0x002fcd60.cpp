// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002fcd60 @ 0x002fcd60
struct Mat34 {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};
class SymTensor {
public:
    int header;
    float xx, xy, xz;
    float yy, yz, zz;
    void FUN_002fcd60(const Mat34* a);
};
void SymTensor::FUN_002fcd60(const Mat34* a)
{
    // Local copy keeps the compiler from sharing x87 temporaries between the products below
    // (the original keeps them unrounded in registers rather than spilling to float).
    Mat34 m = *a;
    float a0 = a->m00, a4 = a->m01, a8 = a->m02;
    float a10 = a->m10, a14 = a->m11, a18 = a->m12;
    float a20 = a->m20, a24 = a->m21, a28 = a->m22;
    float vx = (a0 * xx + a20 * xz) + a10 * xy;
    float vy = (a20 * yz + a10 * yy) + a0 * xy;
    float vz = (a10 * yz + a20 * zz) + a0 * xz;
    float nxx = (((m.m10 * yz + m.m20 * zz) + m.m00 * xz) * a20 + vy * a10) + vx * a0;
    float nxy = (vz * a24 + vy * a14) + vx * a4;
    float nxz = (vy * a18 + vz * a28) + vx * a8;
    float nz = ((a28 * yz + a18 * yy) + a8 * xy) * a18 + ((a8 * xx + a28 * xz) + a18 * xy) * a8 + ((a18 * yz + a28 * zz) + a8 * xz) * a28;
    float nyz = ((m.m11 * yz + m.m21 * zz) + m.m01 * xz) * m.m22 + ((m.m21 * yz + m.m11 * yy) + m.m01 * xy) * m.m12 + ((m.m01 * xx + m.m21 * xz) + m.m11 * xy) * m.m02;
    float ny = a24 * ((a14 * yz + a24 * zz) + a4 * xz) + ((a24 * yz + a14 * yy) + a4 * xy) * a14 + ((a4 * xx + a24 * xz) + a14 * xy) * a4;
    yy = ny;
    yz = nyz;
    zz = nz;
    xx = nxx;
    xy = nxy;
    xz = nxz;
}
