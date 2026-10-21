// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 44/44)
// pure3d::BillboardQuad::vfunc_5 @ 0x002bb630
extern "C" double sqrt(double);

union FloatBits_2bb630 {
    float f;
    unsigned int u;
};

struct Mat_2bb630 {
    char data[0x30];
};

struct V3_2bb630 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
    void FUN_0022d210(const Mat_2bb630 *m);
};

namespace pure3d {

class BillboardQuad {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0xc];
    V3_2bb630 bmin;        // 0x10
    V3_2bb630 bmax;        // 0x1c
    V3_2bb630 ctr;         // 0x28
    float radius;   // 0x34
    char pad38[8];
    Mat_2bb630 mat;        // 0x40
    V3_2bb630 c70;         // 0x70
    char pad7c[4];
    V3_2bb630 half;        // 0x80
    char pad8c[4];
    int flag;       // 0x90
};

void BillboardQuad::vfunc_5()
{
    if (flag != 0) {
        float hx = half.x;
        float hy = half.y;
        float hz = half.z;
        ctr.ix = c70.ix;
        ctr.iy = c70.iy;
        ctr.iz = c70.iz;
        float len = (float)sqrt(hz * hz + hy * hy + hx * hx);
        radius = len;
        V3_2bb630 pn[2];
        pn[0].x = len;
        pn[0].y = len;
        pn[0].z = len;
        float nl = -len;
        pn[1].x = nl;
        pn[1].y = nl;
        pn[1].z = nl;
        pn[0].FUN_0022d210(&mat);
        pn[1].FUN_0022d210(&mat);
        V3_2bb630 &p = pn[0];
        V3_2bb630 &n = pn[1];
        bmax.x = (p.x < n.x) ? n.x : p.x;
        bmax.y = (p.y < n.y) ? n.y : p.y;
        bmax.z = (p.z < n.z) ? n.z : p.z;
        bmin.x = (p.x < n.x) ? p.x : n.x;
        bmin.y = (p.y < n.y) ? p.y : n.y;
        bmin.z = (p.z < n.z) ? p.z : n.z;
        return;
    }

    V3_2bb630 c[8];
    float zn = (half.z > 0.0f) ? -half.z : 0.0f;
    float nx = -half.x;
    c[0].x = nx;
    float ny = -half.y;
    c[0].y = ny;
    c[0].z = zn;
    zn = (half.z > 0.0f) ? -half.z : 0.0f;
    c[1].ix = half.ix;
    c[1].y = ny;
    c[1].z = zn;
    zn = (half.z > 0.0f) ? -half.z : 0.0f;
    c[2].ix = half.ix;
    c[2].iy = half.iy;
    c[2].z = zn;
    zn = (half.z > 0.0f) ? -half.z : 0.0f;
    c[3].x = nx;
    c[3].iy = half.iy;
    c[3].z = zn;
    float zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[4].x = nx;
    c[4].y = ny;
    c[4].z = zp;
    zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[5].ix = half.ix;
    c[5].y = ny;
    c[5].z = zp;
    zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[6].ix = half.ix;
    c[6].iy = half.iy;
    c[6].z = zp;
    zp = (half.z < 0.0f) ? -half.z : 0.0f;
    c[7].x = nx;
    c[7].iy = half.iy;
    c[7].z = zp;
    for (int i = 0; i < 8; i++)
        c[i].FUN_0022d210(&mat);

    bmin.iz = c[0].iz;
    bmin.ix = c[0].ix;
    bmin.iy = c[0].iy;
    bmax.ix = c[0].ix;
    bmax.iy = bmin.iy;
    bmax.iz = bmin.iz;
    for (int i = 1; i < 8; i++) {
        bmax.x = (bmax.x < c[i].x) ? c[i].x : bmax.x;
        bmax.y = (bmax.y < c[i].y) ? c[i].y : bmax.y;
        bmax.z = (bmax.z < c[i].z) ? c[i].z : bmax.z;
        bmin.x = (bmin.x < c[i].x) ? bmin.x : c[i].x;
        bmin.y = (bmin.y < c[i].y) ? bmin.y : c[i].y;
        bmin.z = (bmin.z < c[i].z) ? bmin.z : c[i].z;
    }

    float mxx = bmax.x, mxy = bmax.y, mxz = bmax.z;
    float mnx = bmin.x, mny = bmin.y, mnz = bmin.z;
    // every stage goes through the ctr members (rounded to float) in the original
    volatile float *vc = &ctr.x;
    vc[0] = mxx - mnx;
    vc[1] = mxy - mny;
    vc[2] = mxz - mnz;
    vc[0] = vc[0] * 0.5f;
    vc[1] = vc[1] * 0.5f;
    vc[2] = vc[2] * 0.5f;
    double xy = vc[0] * vc[0] + vc[1] * vc[1]; // MSVC reorders three-term sums; keep x, y, z
    float len = (float)sqrt(xy + vc[2] * vc[2]);
    FloatBits_2bb630 fb;
    fb.f = len;
    fb.u &= 0x7fffffff;
    radius = fb.f;
    vc[0] = mnx + vc[0];
    vc[1] = mny + vc[1];
    vc[2] = mnz + vc[2];
}

}
