// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 138/142, incomplete)
// FUN_00084c40 @ 0x00084c40
struct V3_84c40 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_0022d180();
    float FUN_000111f0();
    V3_84c40 *FUN_00011250(V3_84c40 *out, V3_84c40 *other);
    void FUN_000110d0(V3_84c40 *other);
    void FUN_000110f0(V3_84c40 *other);
    void FUN_00083be0(V3_84c40 *a, V3_84c40 *b);
    void FUN_00083ba0(V3_84c40 *a);
};

struct Matrix {
    float m[16];
    void FUN_0022c3b0(V3_84c40 *in, V3_84c40 *out);
};

struct NameHolder_84c40 {
    char pad[8];
    void FUN_0027af00();
    void FUN_0027af50();
};

struct Args_84c40 {
    float x, y, z, dt;
};

struct Rng_84c40 {
    int s0, s1;
    float FUN_000787e0(float lo, float hi);
    unsigned int FUN_00011330(unsigned int n);
};

struct Probe_84c40 {
    bool FUN_00092940(int id);
};

struct Holder_84c40 {
    Probe_84c40 *FUN_00086340();
};

struct Volume_84c40 {
    bool FUN_001c4010(float *v4);
};

struct CamSub {
    bool FUN_00059a50(V3_84c40 *out);
};

struct Camera {
    char pad00[0x10];
    CamSub *sub;
    void FUN_00035660(V3_84c40 *out);
};

struct CamOwner {
    char pad00[0x124];
    Camera *camera;
};

struct Registry_84c40 {
    void FUN_001dd520(int key, Matrix *out);
    bool FUN_001dd930(int key, NameHolder_84c40 *name);
    int FUN_001dc0d0(int key);
    bool FUN_001dd800(int key);
};

struct Mover_84c40;

struct Controller_84c40 {
    void FUN_001ebe10(Mover_84c40 *who, NameHolder_84c40 *name, const char *effect);
};

struct Manager_84c40 {
    void FUN_0007da40(void *p);
};

struct Globals_84c40 {
    char pad00[0x0c];
    Registry_84c40 *registry;     // 0x0c
    char pad10[0x20 - 0x10];
    CamOwner *camOwner;     // 0x20
    char pad24[0x34 - 0x24];
    Controller_84c40 *controller; // 0x34
    char pad38[0x4c - 0x38];
    Manager_84c40 *manager;       // 0x4c
    char pad50[4];
    Holder_84c40 *holder;         // 0x54
};

extern Globals_84c40 *DAT_004dd700;
extern float DAT_003ff9ac;
extern float DAT_003ff9b0;
extern float DAT_0049bf80;
extern float DAT_0049bf88;

Rng_84c40 *FUN_000964d0();
Volume_84c40 *FUN_001c3d90();
float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
bool __cdecl FUN_00018960(float a, float b, float c);
V3_84c40 *__cdecl FUN_00083dd0(V3_84c40 *out, float s, V3_84c40 *v);
float __cdecl FUN_00083d90(float *v);
void __cdecl FUN_00224d70(float angle, V3_84c40 *v);
float __cdecl FUN_00224f10(V3_84c40 *v);
float __cdecl FUN_00224fc0(float a, float b);

union FloatBits_84c40 {
    float f;
    unsigned int u;
};

struct Frame_84c40 {
    char pad0[3];
    char b13;                       // 0x13
    union { Rng_84c40 *rng; float lo; float t; unsigned int u; int i; } s14;
    union { float dy; unsigned int dyu; float B; } s18;
    V3_84c40 tmp;                         // 0x1c
    union { Controller_84c40 *ctrl; float lo2; float t28; } s28;
    V3_84c40 dir;                         // 0x2c
    union { Registry_84c40 *reg; float A; } s38;
    V3_84c40 d;                           // 0x3c
    union { float len; NameHolder_84c40 name; } s48;
    V3_84c40 hdir;                        // 0x50
    V3_84c40 fwd;                         // 0x5c
    V3_84c40 camPos;                      // 0x68
    float vol[4];                   // 0x74
    Matrix m;                       // 0x84
};

class Mover_84c40 {
public:
    char pad00[0x10];
    int state;              // 0x10
    char active;            // 0x14
    char pad15[3];
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    char pad2c;
    char f2d;
    char pad2e[2];
    int f30;
    int key;                // 0x34
    char pad38[8];
    int f40;
    V3_84c40 f44;
    V3_84c40 f50;
    char pad5c[4];
    V3_84c40 pos;                 // 0x60
    V3_84c40 f6c;
    V3_84c40 f78;
    V3_84c40 f84;
    char pad90[0x9c - 0x90];
    V3_84c40 f9c;
    V3_84c40 fa8;
    float fb4;
    float fb8;
    float fbc;
    float fc0;

    bool FUN_000843c0(V3_84c40 dir, float dt);
    void FUN_00083e60(V3_84c40 d1, V3_84c40 d2, V3_84c40 p);
    void FUN_00084610(float dt);
    void FUN_00084830(float dt);
    void FUN_00084c40(float dt);
};

void Mover_84c40::FUN_00084c40(float dt)
{
    Frame_84c40 fr;
    Globals_84c40 *g = DAT_004dd700;
    Probe_84c40 *probe = g->holder->FUN_00086340();
    fr.b13 = probe->FUN_00092940(0x25);
    fr.s38.reg = DAT_004dd700->registry;
    fr.s28.ctrl = DAT_004dd700->controller;
    CamOwner *owner = DAT_004dd700->camOwner;
    fr.s14.rng = FUN_000964d0();

    fr.vol[0] = pos.x;
    fr.vol[1] = pos.y;
    fr.vol[2] = pos.z;
    fr.vol[3] = 5.0f;
    if (FUN_001c3d90()->FUN_001c4010(fr.vol)) {
        f2d = 1;
    } else if (f2d) {
        f30 = 0;
        f2d = 0;
    } else {
        f30++;
    }

    Camera *cam = owner->camera;
    cam->sub->FUN_00059a50(&fr.camPos);
    fr.s38.reg->FUN_001dd520(key, &fr.m);
    fr.d.x = fr.camPos.x - fr.m.m[12];
    fr.d.y = 0;
    fr.s18.dy = fr.camPos.y - fr.m.m[13];
    fr.d.z = fr.camPos.z - fr.m.m[14];
    fr.s48.len = fr.d.FUN_0022d110();
    fr.fwd.x = -1.0f;
    fr.fwd.y = 0;
    fr.fwd.z = 0;
    fr.m.FUN_0022c3b0(&fr.fwd, &fr.dir);

    if (!active) {
        fr.s18.dyu &= 0x7fffffff;
        if (fr.s18.dy < 4.0f && !probe->FUN_00092940(0x25)
            && (fr.s48.len < f28
                || (fr.s48.len < f24
                    && ((fr.dir.y * fr.d.y + fr.dir.x * fr.d.x) + fr.dir.z * fr.d.z) > 0.7f))) {
            active = 1;
            cam->FUN_00035660(&fr.hdir);
            if (((fr.hdir.y * fr.d.y + fr.hdir.x * fr.d.x) + fr.hdir.z * fr.d.z) < 0.0f) {
                state = 0xf;
                f78.FUN_00083be0(&fr.d, &fr.dir);
                f78.FUN_00083ba0(&fr.dir);
                f78.FUN_0022d180();
                V3_84c40 &p = fr.fwd;
                fr.s18.dy = f28;
                fr.tmp.x = (fr.dir.x + f78.x) * fr.s18.dy;
                p.z = fr.dir.z + f78.z;
                p.y = (fr.dir.y + f78.y) * fr.s18.dy + pos.y;
                p.x = fr.tmp.x + pos.x;
                p.z = p.z * fr.s18.dy + pos.z;
                FUN_00083e60(fr.dir, f78, p);
                fbc = 0;
                fc0 = fr.s14.rng->FUN_000787e0(0.3f, 1.3f);
                if (fc0 > 0.9f)
                    fc0 = 1.3f;
                fr.s48.name.FUN_0027af00();
                if (fr.s38.reg->FUN_001dd930(key, &fr.s48.name)) {
                    fr.s28.ctrl->FUN_001ebe10(this, &fr.s48.name, "skid");
                    if (fr.s14.rng->FUN_00011330(2) == 0)
                        fr.s28.ctrl->FUN_001ebe10(this, &fr.s48.name, "horn");
                }
                fr.s48.name.FUN_0027af50();
            } else {
                state = 0x11;
                fr.tmp.z = -fr.d.z;
                f78.x = -fr.d.x;
                f78.y = -fr.d.y;
                f78.z = fr.tmp.z;
                fr.s48.name.FUN_0027af00();
                if (fr.s38.reg->FUN_001dd930(key, &fr.s48.name))
                    fr.s28.ctrl->FUN_001ebe10(this, &fr.s48.name, "skid");
                fr.s48.name.FUN_0027af50();
            }
        }
    }

    if (active) {
        if (fr.s38.reg->FUN_001dc0d0(key) == 0)
            return;
    }

    switch (state) {
    case 3:
    case 4:
    case 0xd:
        return;
    case 0xf: {
        fr.s14.lo = 0;
        f18 = dt * f20 + f18;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, &DAT_003ff9ac);
        if (FUN_000843c0(f78, dt))
            break;
        f6c = fr.dir;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 0x10: {
        fr.s28.lo2 = 0;
        f18 = f18 - dt * 10.0f;
        f18 = FUN_000186b0(&f18, &fr.s28.lo2, &DAT_003ff9ac);
        fr.s28.t28 = f18 * dt;
        double cr = (double)f78.z * f84.x - (double)f84.z * f78.x;
        if (cr == 0.0)
{
            fr.s14.i = (int)(fr.s14.rng->FUN_00011330(1) * 2 - 1);
            cr = fr.s14.i;
            if (fr.s14.i < 0)
                cr += 4294967296.0;
        }
        fbc = fr.s28.t28 + fbc;
        f6c = f84;
        fr.s18.B = fbc / fb8;
        if (cr > 0.0)
            FUN_00224d70(fr.s18.B, &f6c);
        else
            FUN_00224d70(-fr.s18.B, &f6c);
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, fr.s28.t28, &f84));
        if (f18 == 0.0f) {
            if (((fr.dir.y * fr.d.y + fr.dir.x * fr.d.x) + fr.dir.z * fr.d.z) < 0.0f) {
                state = 0xf;
                fbc = 100.0f;
            } else {
                state = 0x12;
                f84 = f6c;
            }
        }
        break;
    }
    case 0x11: {
        fr.s14.lo = 0;
        f18 = f18 - dt * 20.0f;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, &DAT_003ff9ac);
        f6c = fr.dir;
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        if (FUN_00018960(f18, 0.0f, 1e-05f)) {
            state = 0x12;
            f84 = f6c;
        }
        break;
    }
    case 0x12: {
        fr.s14.lo = 0;
        f18 = dt * 10.0f + f18;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, &DAT_003ff9b0);
        fr.tmp.z = -fr.d.z;
        f78.x = -fr.d.x;
        f78.y = -fr.d.y;
        f78.z = fr.tmp.z;
        fr.hdir.x = -fr.dir.x;
        fr.hdir.y = -fr.dir.y;
        fr.hdir.z = -fr.dir.z;
        fr.s38.A = FUN_00224f10(&fr.hdir);
        fr.hdir.x = -f84.x;
        fr.hdir.y = -f84.y;
        fr.hdir.z = -f84.z;
        fr.s18.B = FUN_00224f10(&fr.hdir);
        fr.s14.lo = FUN_00224f10(&f78);
        fr.s18.B = FUN_00224fc0(fr.s18.B, fr.s38.A);
        fr.s28.t28 = fr.s18.B;
        fr.s18.dyu &= 0x7fffffff;
        if (fr.s18.B < 0.01745329238474369f) {
            fr.s28.t28 = FUN_00224fc0(fr.s38.A, fr.s14.lo);
            float sg = FUN_00083d90(&fr.s28.t28);
            if (sg == 0.0f)
                sg = 1.0f;
            f84.z = DAT_0049bf88;
            f84.x = DAT_0049bf80;
            f84.y = 0;
            FUN_00224d70(sg * 0.17453293f + fr.s14.lo, &f84);
            fr.tmp.z = -f84.z;
            f84.x = -f84.x;
            f84.y = -f84.y;
            f84.z = fr.tmp.z;
            fr.hdir.x = -f84.x;
            fr.hdir.y = -f84.y;
            fr.hdir.z = -f84.z;
            fr.s18.B = FUN_00224f10(&fr.hdir);
            fr.s28.t28 = FUN_00224fc0(fr.s18.B, fr.s38.A);
        }
        f6c.z = DAT_0049bf88;
        f6c.x = DAT_0049bf80;
        f6c.y = 0;
        FUN_00224d70(fr.s38.A - (FUN_00083d90(&fr.s28.t28) * dt) * 0.69813174f, &f6c);
        fr.tmp.z = -f6c.z;
        f6c.x = -f6c.x;
        f6c.y = -f6c.y;
        f6c.z = fr.tmp.z;
        pos.FUN_000110f0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 5: {
        V3_84c40 *r = f9c.FUN_00011250(&fr.tmp, &pos);
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 7;
            fbc = 0;
            f6c = fr.dir;
            pos = f9c;
            break;
        }
        f6c = fr.dir;
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 6: {
        V3_84c40 *r = f9c.FUN_00011250(&fr.tmp, &pos);
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 8;
            fbc = 0;
            f6c = fr.dir;
            pos = f9c;
            break;
        }
        f6c = fr.dir;
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 7: {
        if (!fr.s38.reg->FUN_001dd800(key)) {
            DAT_004dd700->manager->FUN_0007da40((char *)this + 8);
            return;
        }
        V3_84c40 *r = f50.FUN_00011250(&fr.tmp, &f44);
        if (FUN_000843c0(*r, dt))
            break;
        state = 11;
        r = f50.FUN_00011250(&fr.tmp, &fa8);
        f6c = *r;
        pos = fa8;
        break;
    }
    case 8: {
        if (!fr.s38.reg->FUN_001dd800(key)) {
            DAT_004dd700->manager->FUN_0007da40((char *)this + 8);
            return;
        }
        V3_84c40 *r = f50.FUN_00011250(&fr.tmp, &f44);
        if (FUN_000843c0(*r, dt))
            break;
        state = 12;
        r = f50.FUN_00011250(&fr.tmp, &fa8);
        f6c = *r;
        pos = fa8;
        break;
    }
    case 9: {
        V3_84c40 *r = f44.FUN_00011250(&fr.tmp, &pos);
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 11;
            r = f50.FUN_00011250(&fr.tmp, &f44);
            f6c = *r;
            pos = f44;
            break;
        }
        r = f44.FUN_00011250(&fr.tmp, &pos);
        f6c = *r;
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 10: {
        V3_84c40 *r = f44.FUN_00011250(&fr.tmp, &pos);
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 12;
            r = f50.FUN_00011250(&fr.tmp, &f44);
            f6c = *r;
            pos = f44;
            break;
        }
        r = f44.FUN_00011250(&fr.tmp, &pos);
        f6c = *r;
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 0xe: {
        if (!fr.s38.reg->FUN_001dd800(key)) {
            DAT_004dd700->manager->FUN_0007da40((char *)this + 8);
            return;
        }
        V3_84c40 *r;
        if (FUN_00018960(fb8, 0.0f, 1e-05f)) {
            state = 0;
            r = f44.FUN_00011250(&fr.tmp, &pos);
            f6c = *r;
            f6c.FUN_0022d180();
            if (fr.b13)
                f18 = f1c;
            pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
            break;
        }
        r = f50.FUN_00011250(&fr.tmp, &f44);
        if (FUN_000843c0(*r, dt))
            break;
        state = 0;
        r = f50.FUN_00011250(&fr.tmp, &fa8);
        f6c = *r;
        pos = fa8;
        break;
    }
    case 1: {
        V3_84c40 *r = f50.FUN_00011250(&fr.tmp, &pos);
        f6c = *r;
        if (f6c.FUN_000111f0() <= 16.0f) {
            f18 = 0;
            state = 3;
            return;
        }
        fr.s14.lo = 2.0f;
        f18 = f18 - dt * 5.0f;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, &f1c);
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 2: {
        V3_84c40 *r = f50.FUN_00011250(&fr.tmp, &pos);
        f6c = *r;
        if (f6c.FUN_000111f0() <= 16.0f) {
            f18 = 0;
            state = 4;
            return;
        }
        fr.s14.lo = 2.0f;
        f18 = f18 - dt * 5.0f;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, &f1c);
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    case 0: {
        V3_84c40 *r = f50.FUN_00011250(&fr.tmp, &pos);
        f6c = *r;
        int t = f40;
        if (t == 0 || t == 5) {
            if (f6c.FUN_000111f0() <= 100.0f)
                state = 1;
        } else if (t == 1 || t == 4) {
            if (f6c.FUN_000111f0() <= 100.0f)
                state = 2;
        } else if (t == 2 || t == 3) {
            if (f6c.FUN_000111f0() <= 16.0f) {
                state = 0xd;
                return;
            }
        }
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        pos.FUN_000110d0(FUN_00083dd0(&fr.tmp, dt * f18, &f6c));
        break;
    }
    }

    if (!active && !fr.b13)
        FUN_00084610(dt);
    FUN_00084830(dt);
}
