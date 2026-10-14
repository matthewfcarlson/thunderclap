// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 38/38)
// FUN_00319f40 @ 0x00319f40
extern float DAT_004d2960;

union Bits_319f40 {
    float f;
    unsigned int u;
};

struct V3_319f40 {
    float x, y, z;
    float FUN_00018990() throw();
};

struct Body_319f40 {
    char pad00[0x50];
    V3_319f40 pos;                     // 0x50
    V3_319f40 vel;                     // 0x5c
    char pad68[0x18];
    float f80;                  // 0x80
};

struct Event_319f40 {
    int type;                   // 0x00
    Bits_319f40 a[6];                  // 0x04
    Bits_319f40 f1c;                   // 0x1c
    char pad20[0x10];
    V3_319f40 diff;                    // 0x30
    Bits_319f40 f3c;                   // 0x3c
    Bits_319f40 f40;                   // 0x40
    char pad44[0x14];
    void FUN_0031a830() throw();
};

struct Tracker_319f40 {
    char pad00[0x10];
    int state;                  // 0x10
    Bits_319f40 f14;
    Bits_319f40 f18;
    Bits_319f40 f1c;
    Bits_319f40 f20;
    Bits_319f40 f24;
    Bits_319f40 f28;
    Bits_319f40 f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    V3_319f40 v40;                     // 0x40
    Bits_319f40 f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    char pad64[4];
    float f68;
    float f6c;
    Body_319f40 *a;                    // 0x70
    Body_319f40 *b;                    // 0x74
    char pad78[8];
    unsigned int flags;         // 0x80
    char flag84;
    char pad85[3];
    int count;                  // 0x88
    Bits_319f40 f8c;
    Bits_319f40 f90;
    Bits_319f40 f94;
    Bits_319f40 f98;
    Bits_319f40 f9c;
    void FUN_00319e90(int what, void *arg) throw();
    void FUN_00319f40();
};

void Tracker_319f40::FUN_00319f40()
{
    int n = count;
    if (n == 0)
        return;
    if (n > 1) {
        double inv = 1.0f / n;
        f90.f = inv * f90.f;
        f8c.f = inv * f8c.f;
        f14.f = inv * f14.f;
        f18.f = inv * f18.f;
        f1c.f = inv * f1c.f;
        f20.f = inv * f20.f;
        f24.f = inv * f24.f;
        f28.f = inv * f28.f;
    }
    double t = f90.f * 0.05f + f50 * 0.95f;
    f50 = t;
    if (t == 0.0)
        f50 = 0.00001f;

    double d = f94.f - f98.f;
    f4c.u = f8c.u;
    bool big = d > f60;
    if (!big) {
        unsigned int g = f8c.u;
        Bits_319f40 absg;
        absg.u = g & 0x7fffffff;
        double dbl = f9c.f;
        dbl = dbl + dbl;
        if (dbl < absg.f) {
            absg.u = f8c.u & 0x7fffffff;
            if (absg.f > f5c)
                big = true;
        }
    }

    if (big) {
        if (flags & 1) {
            if (state == 2) {
                state = 0;
                FUN_00319e90(3, &state);
            }
            Event_319f40 e;
            e.FUN_0031a830();
            Body_319f40 *pa = a;
            Body_319f40 *pb = b;
            e.a[0] = f14;
            e.a[1] = f18;
            e.a[2] = f1c;
            e.a[3] = f20;
            e.a[4] = f24;
            e.a[5] = f28;
            e.type = 1;
            e.f1c = f94;
            e.diff.x = pa->pos.x - pb->pos.x;
            e.diff.y = pa->pos.y - pb->pos.y;
            e.diff.z = pa->pos.z - pb->pos.z;
            Bits_319f40 eb = f8c;
            e.f40 = f90;
            Bits_319f40 absg;
            absg.u = eb.u & 0x7fffffff;
            f9c.u = absg.u;
            e.f3c = eb;
            FUN_00319e90(1, &e);
        }
    } else if (flags & 0xe) {
        Body_319f40 *pa = a;
        Body_319f40 *pb = b;
        double dx = pa->pos.x - pb->pos.x;
        double dy = pa->pos.y - pb->pos.y;
        volatile float dz = pa->pos.z - pb->pos.z;
        volatile V3_319f40 *vv = &v40;
        vv->x = vv->x * 0.95f;
        vv->y = vv->y * 0.95f;
        vv->z = vv->z * 0.95f;
        vv->x = dx * 0.05f + vv->x;
        vv->y = dy * 0.05f + vv->y;
        vv->z = dz * 0.05f + vv->z;
        unsigned int fl = flags;
        if (fl & 8) {
            if (fl & 0x800) {
                Body_319f40 *p = a;
                double h = 1.0f / DAT_004d2960;
                Bits_319f40 ab;
                ab.u = *(unsigned int *)&f50 & 0x7fffffff;
                double w = (h + DAT_004d2960) * p->f80 * 0.5f * 0.05f + f54 * 0.95f;
                volatile float v = w;
                f54 = w;
                float len = p->vel.FUN_00018990();
                double r = len / ((v + ab.f) * 0.5f);
                if (r > 15.0f)
                    f38 = r;
                else
                    f38 = 0.0f;
            }
            if (fl & 0x80000) {
                Body_319f40 *p = b;
                double h = 1.0f / DAT_004d2960;
                Bits_319f40 ab;
                ab.u = *(unsigned int *)&f50 & 0x7fffffff;
                double w = (h + DAT_004d2960) * p->f80 * 0.5f * 0.05f + f58 * 0.95f;
                volatile float v = w;
                f58 = w;
                float len = p->vel.FUN_00018990();
                double r = len / ((v + ab.f) * 0.5f);
                if (r > 15.0f)
                    f3c = r;
                else
                    f3c = 0.0f;
            }
        }
        if ((fl & 6) == 6) {
            double r2d = v40.FUN_00018990() / f50;
            volatile float r2 = r2d;
            if (r2d < f68) {
                f30 = 1.0f;
                f34 = 0.0f;
            } else if (r2 > f6c) {
                f30 = 0.0f;
                f34 = 1.0f;
            } else {
                double u = (r2 - f68) / (f6c - f68);
                f34 = u;
                f30 = 1.0 - u;
            }
        }
        if (state != 2) {
            f2c = f94;
            state = 2;
            FUN_00319e90(2, &state);
        }
        f9c.u = 0;
    }
    f98 = f94;
    count = 0;
    flag84 = 1;
}
