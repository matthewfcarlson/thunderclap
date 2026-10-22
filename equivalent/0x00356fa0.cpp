// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 0/0)
// FUN_00356fa0 @ 0x00356fa0
#include "decls/data/engine/pure3d.h"
#include "compat/ptr.h"

struct Grad_356fa0 {
    float x, y, z;
};


hulk_freg __stdcall FUN_00356fa0(float *p)
{
    double x = p[0] + 4096.0f;
    int xa = (int)(__int64)x;
    double fx = x - xa;
    int xi = xa & 0xff;
    float fx1 = (hulk_freg)(fx - 1.0f);

    double y = p[1] + 4096.0f;
    int ya = (int)(__int64)y;
    double fy = y - ya;
    int yi = ya & 0xff;
    int yi1 = (yi + 1) & 0xff;
    float fy1 = (hulk_freg)(fy - 1.0f);

    double z = p[2] + 4096.0f;
    int za = (int)(__int64)z;
    int zi = za & 0xff;
    int zi1 = (zi + 1) & 0xff;
    float fz = (hulk_freg)(z - za);

    int xi1 = (xi + 1) & 0xff;
    int a = DAT_0056bfc8[xi];
    int b = DAT_0056bfc8[xi1];
    int aa = DAT_0056bfc8[a + yi];
    int ab = DAT_0056bfc8[a + yi1];
    int ba = DAT_0056bfc8[b + yi];
    int bb = DAT_0056bfc8[b + yi1];

    hulk_freg fz1 = fz - 1.0f;
    float u = (hulk_freg)((3.0f - (fx + fx)) * fx * fx);
    float v = (hulk_freg)((3.0f - (fy + fy)) * fy * fy);

    const Grad_356fa0 &g000 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + aa];
    const Grad_356fa0 &g100 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + ba];
    const Grad_356fa0 &g010 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + ab];
    const Grad_356fa0 &g110 = ((Grad_356fa0*)&DAT_0056c7d0)[zi + bb];
    const Grad_356fa0 &g001 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + aa];
    const Grad_356fa0 &g101 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + ba];
    const Grad_356fa0 &g011 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + ab];
    const Grad_356fa0 &g111 = ((Grad_356fa0*)&DAT_0056c7d0)[zi1 + bb];

    double d000 = fz * g000.z + fy * g000.y + fx * g000.x;
    double d100 = fz * g100.z + fy * g100.y + fx1 * g100.x;
    double l00 = d000 + (d100 - d000) * u;
    double d010 = fz * g010.z + fy1 * g010.y + fx * g010.x;
    double d110 = fz * g110.z + fy1 * g110.y + fx1 * g110.x;
    double l10 = d010 + (d110 - d010) * u;
    float m0 = (hulk_freg)(l00 + (l10 - l00) * v);

    double d001 = fz1 * g001.z + fy * g001.y + fx * g001.x;
    double d101 = fz1 * g101.z + fy * g101.y + fx1 * g101.x;
    float l01 = (hulk_freg)(d001 + (d101 - d001) * u);
    double d011 = fz1 * g011.z + fy1 * g011.y + fx * g011.x;
    double d111 = fz1 * g111.z + fy1 * g111.y + fx1 * g111.x;
    double l11 = d011 + (d111 - d011) * u;
    double m1 = l01 + (l11 - l01) * v;

    double w = (3.0f - (fz + fz)) * fz * fz;
    return (hulk_freg)(m0 + (m1 - m0) * w);
}
