// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_00315860 @ 0x00315860
union Bits {
    float f;
    unsigned int u;
};

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct BoxData {
    char pad00[0x38];
    int f38;                    // 0x38
    char pad3c[0xc];
    float ext[3];               // 0x48
    V3 axis[3];                 // 0x54
};

class Shape {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3 *getCenter();
    char pad04[0x30];
    float radius;               // 0x34
    char pad38[0xc];
    V3 v44;                     // 0x44
    float f50;                  // 0x50
    float f54;                  // 0x54
};

class Tester {
public:
    char pad00[0xc];
    float f0c;                  // 0x0c
    char pad10[4];
    V3 v14;                     // 0x14
    void FUN_00314be0(BoxData *box, V3 *q, Shape *shape, V3 *p, float d, V3 *out);
    void FUN_00315860(BoxData *box, Shape *shape);
};

void Tester::FUN_00315860(BoxData *box, Shape *shape)
{
    struct Frame {
        float sgn;
        float pad14;
        float r1;
        float r2;
        float e;
        float sgn2;
        float f;
        float absf;
        V3 P;
        V3 c;
        V3 q48;
        V3 w;
        V3 out;
    } fr;
    Bits ab;
    float *cv = &fr.c.x;

    if (box->f38 == 0) {
        fr.c.x = box->axis[0].z * v14.z + box->axis[0].y * v14.y + box->axis[0].x * v14.x;
        fr.c.y = box->axis[1].z * v14.z + box->axis[1].y * v14.y + box->axis[1].x * v14.x;
        fr.c.z = box->axis[2].z * v14.z + box->axis[2].y * v14.y + box->axis[2].x * v14.x;
    } else {
        fr.c = v14;
    }

    for (int i = 0; i < 3; i++) {
        ab.f = cv[i];
        ab.u &= 0x7fffffff;
        double dd0 = ab.f - box->ext[i];
        float d = dd0;
        if (!(dd0 > 0.0))
            continue;
        if (!(shape->radius + f0c > d))
            continue;
        bool flag = true;
        if (cv[i] < 0.0f)
            fr.sgn = -1.0f;
        else if (cv[i] > 0.0f)
            fr.sgn = 1.0f;
        else
            fr.sgn = 0.0f;
        fr.sgn2 = fr.sgn;
        V3 *row = &box->axis[i];
        fr.e = row->z * shape->v44.z + row->y * shape->v44.y + row->x * shape->v44.x;

        for (;;) {
            float s2;
            if (fr.e < 0.0f)
                s2 = -1.0f;
            else if (fr.e > 0.0f)
                s2 = 1.0f;
            else
                s2 = 0.0f;
            double k = s2 * shape->f50 * fr.sgn2;
            fr.P.x = k * shape->v44.x;
            fr.P.y = k * shape->v44.y;
            fr.P.z = k * shape->v44.z;
            double ux = row->y * shape->v44.z - row->z * shape->v44.y;
            double uy = row->z * shape->v44.x - row->x * shape->v44.z;
            double uz = row->x * shape->v44.y - row->y * shape->v44.x;
            fr.w.x = uz * shape->v44.y - uy * shape->v44.z;
            fr.w.y = ux * shape->v44.z - uz * shape->v44.x;
            fr.w.z = uy * shape->v44.x - ux * shape->v44.y;
            fr.w.FUN_0022d110();
            double m = fr.sgn * shape->f54;
            fr.P.x = fr.w.x * m + fr.P.x;
            fr.P.y = fr.w.y * m + fr.P.y;
            fr.P.z = fr.w.z * m + fr.P.z;
            fr.f = fr.P.z * row->z + fr.P.y * row->y + fr.P.x * row->x;
            ab.f = fr.f;
            ab.u &= 0x7fffffff;
            fr.absf = ab.f;
            double dd = d - fr.absf;
            d = dd;
            if (dd <= f0c) {
                int j = (i >= 2) ? 0 : i + 1;
                V3 *rj = &box->axis[j];
                fr.r1 = cv[j] - (fr.P.z * rj->z + fr.P.y * rj->y + fr.P.x * rj->x);
                ab.f = fr.r1;
                ab.u &= 0x7fffffff;
                if (ab.f - box->ext[j] <= 0.0f) {
                    int k2 = (j >= 2) ? 0 : j + 1;
                    V3 *rk = &box->axis[k2];
                    fr.r2 = cv[k2] - (fr.P.z * rk->z + fr.P.y * rk->y + fr.P.x * rk->x);
                    ab.f = fr.r2;
                    ab.u &= 0x7fffffff;
                    if (ab.f - box->ext[k2] <= 0.0f) {
                        V3 *cc = shape->getCenter();
                        fr.P.x = fr.P.x + cc->x;
                        fr.P.y = fr.P.y + cc->y;
                        fr.P.z = fr.P.z + cc->z;
                        double t = fr.sgn * d;
                        float y1 = t * row->y;
                        float z1 = t * row->z;
                        fr.q48.x = t * row->x + fr.P.x;
                        fr.q48.y = y1 + fr.P.y;
                        fr.q48.z = z1 + fr.P.z;
                        fr.out.x = fr.sgn * row->x;
                        fr.out.y = fr.sgn * row->y;
                        fr.out.z = fr.sgn * row->z;
                        FUN_00314be0(box, &fr.q48, shape, &fr.P, d, &fr.out);
                    }
                }
            }
            if (!flag)
                break;
            ab.f = fr.e;
            ab.u &= 0x7fffffff;
            if (!(2.0 * (ab.f * shape->f50) + d <= f0c))
                break;
            fr.sgn2 = -fr.sgn2;
            ab.f = cv[i];
            ab.u &= 0x7fffffff;
            flag = false;
            d = ab.f - box->ext[i];
        }
    }
}
