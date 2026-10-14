// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 74/84, incomplete)
// CWeaponCollisionAction::vfunc_8 @ 0x0001c9b0
extern "C" double sqrt(double);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct V3_1c9b0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat_1c9b0 {
    char pad0[0x30];
    V3_1c9b0 pos;
    float w;
    void FUN_0022b980();
    void FUN_0022c2b0(const V3_1c9b0 *in, V3_1c9b0 *out);
};

struct EntA {
    int FUN_001d64a0();
};

struct SrcEnt {
    char pad0[8];
    EntA *f8;
    int kind;
    Mat_1c9b0 mat;
};

struct Config_1c9b0 {
    char pad0[0x18];
    float scale;
    int f1c;
    int f20;
};

extern float DAT_003f2ecc;
void __cdecl FUN_00224ce0(Mat_1c9b0 *a, Mat_1c9b0 *b, float t, Mat_1c9b0 *out);
float __cdecl FUN_000186f0(float *a, float *b);
char __cdecl FUN_00096ce0(SrcEnt *src, V3_1c9b0 *hit, float *out);

class CWeaponCollisionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(int a1);
    char pad04[0x18];
    void *owner;
    Config_1c9b0 *cfg;
    SrcEnt *src;
    char b28;
    char pad29[3];
    int f2c;
    int f30;
    Mat_1c9b0 xf;
    void FUN_0001c430(Mat_1c9b0 *m);
    void FUN_0001c770(Mat_1c9b0 *m, float radius);
};

bool CWeaponCollisionAction::vfunc_8(int a1)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        V3_1c9b0 d0;
        V3_1c9b0 tc;
        V3_1c9b0 q;
        int s30;
        V3_1c9b0 tin;
        V3_1c9b0 pp;
        Mat_1c9b0 M;
        Mat_1c9b0 M2;
    } f;

    if (src == 0)
        return false;
    int type = 0;
    if (src->kind == 5)
        type = src->f8->FUN_001d64a0();

    if (b28) {
        Mat_1c9b0 *sm = &src->mat;
        float r25 = cfg->scale * 0.25f;
        f.tc.x = xf.pos.x;
        f.tc.y = xf.pos.y;
        f.s0 = (float)(r25 + r25);
        f.d0.x = sm->pos.x;
        f.tc.z = xf.pos.z;
        f.d0.x = f.d0.x - f.tc.x;
        f.d0.y = sm->pos.y;
        f.d0.z = sm->pos.z;
        f.d0.y = f.d0.y - f.tc.y;
        f.tin.x = 0.0f;
        f.d0.z = f.d0.z - f.tc.z;
        f.tin.y = 3.5f;
        f.tin.z = 0.0f;
        sm->FUN_0022c2b0(&f.tin, &f.pp);
        xf.FUN_0022c2b0(&f.tin, &f.q);
        double ex = f.pp.x - f.q.x;
        double ey = f.pp.y - f.q.y;
        double ez = f.pp.z - f.q.z;
        f.s4 = (float)sqrt(ez * ez + ey * ey + ex * ex);
        double len2 = sqrt((double)f.d0.z * f.d0.z + (double)f.d0.y * f.d0.y + (double)f.d0.x * f.d0.x);
        double maxd = len2;
        if (f.s4 > len2)
            maxd = f.s4;
        if (maxd < f.s0) {
            FUN_0001c430(sm);
        } else {
            double n = maxd / f.s0;
            int cnt = (int)n;
            if ((double)(n - (double)cnt) > 0.0)
                cnt++;
            if (cnt > 0x40)
                cnt = 0x40;
            int last = cnt - 1;
            bool done = false;
            if (last > 0) {
                f.s0 = (float)cnt;
                int i = 0;
                do {
                    int next = i + 1;
                    f.s4 = (float)next;
                    FUN_00224ce0(&xf, sm, (float)((double)f.s4 / f.s0), &f.M);
                    FUN_0001c430(&f.M);
                    Config_1c9b0 *c = cfg;
                    if (c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20) {
                        done = true;
                        break;
                    }
                    i = next;
                } while (i < last);
            }
            if (!done) {
                Config_1c9b0 *c = cfg;
                if (!(c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20))
                    FUN_0001c430(sm);
            }
        }
        memcpy(&xf, sm, sizeof(Mat_1c9b0));
    } else if (type != 0) {
        SrcEnt *s = src;
        f.s8 = 1.0f;
        char ok = FUN_00096ce0(s, &f.q, &f.s8);
        if (ok) {
            f.M.FUN_0022b980();
            f.s8 = f.s8 * 0.75f;
            f.M.pos = f.q;
        } else {
            memcpy(&f.M, &src->mat, sizeof(Mat_1c9b0));
            f.s8 = 1.0f;
        }
        int ebp = type;
        float m;
        if (ebp == 3 || ebp == 4) {
            if (f.s8 < 1.5f)
                m = f.s8;
            else
                m = 1.5f;
            if (f.s8 < 1.5f && m < 0.25f)
                m = 0.25f;
        } else {
            f.s0 = FUN_000186f0(&f.s8, &DAT_003f2ecc);
            if (f.s0 < 0.25f)
                f.s0 = 0.25f;
            m = f.s0;
        }
        f.d0 = xf.pos;
        f.tc = f.M.pos;
        double dx2 = f.tc.x - f.d0.x;
        double dy2 = f.tc.y - f.d0.y;
        double dz2 = f.tc.z - f.d0.z;
        double len = sqrt(dz2 * dz2 + dy2 * dy2 + dx2 * dx2);
        double m2 = m + m;
        if (len < m2) {
            FUN_0001c770(&f.M, m);
        } else {
            double r = len / m2;
            int cnt = (int)r;
            if ((double)(r - (double)cnt) > 0.0)
                cnt++;
            if (cnt > 0x40)
                cnt = 0x40;
            f.s4 = (float)cnt;
            int last = cnt - 1;
            f.s30 = last;
            bool done = false;
            if (last > 0) {
                f.s0 = (float)cnt;
                int i = 0;
                do {
                    int next = i + 1;
                    f.s4 = (float)next;
                    FUN_00224ce0(&xf, &f.M, (float)((double)f.s4 / f.s0), &f.M2);
                    FUN_0001c770(&f.M2, m);
                    Config_1c9b0 *c = cfg;
                    if (c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20) {
                        done = true;
                        break;
                    }
                    i = next;
                } while (i < last);
            }
            if (!done) {
                Config_1c9b0 *c = cfg;
                if (!(c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20))
                    FUN_0001c770(&f.M, m);
            }
        }
        memcpy(&xf, &f.M, sizeof(Mat_1c9b0));
    }

    Config_1c9b0 *ce = cfg;
    bool reached = ce->f1c > 0 && f2c >= ce->f1c && ce->f20 > 0 && f30 >= ce->f20;
    return !reached;
}
