// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_002fcd60 @ 0x002fcd60
#include "compat/ptr.h"
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
// x87 (the listing's precision): vx and vy go through the frame (rounded); vz is used once from its register and
// then from a rounded copy; the new xx, xy, xz and the row sums stay in registers (53 bits) until they are stored;
// yy, yz, zz are rounded frame copies. Sums in the listing's order.
void SymTensor::FUN_002fcd60(const Mat34* a)
{
    float a0 = a->m00, a4 = a->m01, a8 = a->m02;
    float a10 = a->m10, a14 = a->m11, a18 = a->m12;
    float a20 = a->m20, a24 = a->m21, a28 = a->m22;
    volatile float vx = ((hulk_freg)a0 * xx + (hulk_freg)a20 * xz) + (hulk_freg)a10 * xy;
    volatile float vy = ((hulk_freg)a20 * yz + (hulk_freg)a10 * yy) + (hulk_freg)a0 * xy;
    hulk_freg vzu = ((hulk_freg)a10 * yz + (hulk_freg)a20 * zz) + (hulk_freg)a0 * xz;
    volatile float vz = (float)vzu;
    hulk_freg nxx = (vzu * a20 + (hulk_freg)vy * a10) + (hulk_freg)vx * a0;
    hulk_freg nxz = ((hulk_freg)vy * a18 + (hulk_freg)vz * a28) + (hulk_freg)vx * a8;
    hulk_freg nxy = ((hulk_freg)vz * a24 + (hulk_freg)vy * a14) + (hulk_freg)vx * a4;
    hulk_freg u1 = ((hulk_freg)a4 * xx + (hulk_freg)a24 * xz) + (hulk_freg)a14 * xy;
    hulk_freg u2 = ((hulk_freg)a24 * yz + (hulk_freg)a14 * yy) + (hulk_freg)a4 * xy;
    hulk_freg u3 = ((hulk_freg)a14 * yz + (hulk_freg)a24 * zz) + (hulk_freg)a4 * xz;
    volatile float ny = (a24 * u3 + u2 * a14) + u1 * a4;
    volatile float nyz = (u3 * a28 + u2 * a18) + u1 * a8;
    hulk_freg w2 = ((hulk_freg)a28 * yz + (hulk_freg)a18 * yy) + (hulk_freg)a8 * xy;
    hulk_freg w1 = ((hulk_freg)a8 * xx + (hulk_freg)a28 * xz) + (hulk_freg)a18 * xy;
    hulk_freg w3 = ((hulk_freg)a18 * yz + (hulk_freg)a28 * zz) + (hulk_freg)a8 * xz;
    volatile float nz = (w2 * a18 + w1 * a8) + w3 * a28;
    yy = ny;
    yz = nyz;
    zz = nz;
    xx = (float)nxx;
    xy = (float)nxy;
    xz = (float)nxz;
}
