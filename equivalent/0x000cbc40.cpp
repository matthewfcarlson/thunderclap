// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 150/150)
// FUN_000cbc40 @ 0x000cbc40
#include "decls/address.h"
#include "decls/data/game/global.h"
extern char DAT_0049fd74[];
extern char DAT_0049fd9c[];

extern float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
// equiv-conv: FUN_000cb7d0 ecx edx stack
extern void __cdecl FUN_000cb7d0(float *cur, float *target, float step);

class UiObj_cbc40 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float a, int b);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(float a);
    virtual float v13();
    virtual void v14(float a, float b);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual char v22();
};

struct UiVec_cbc40 {
    char pad0[0x24];
    UiObj_cbc40 **begin;
    UiObj_cbc40 **end;
};

struct Probe_cbc40 {
    char FUN_00092940(int id);
};

struct Pawn_cbc40 {
    char pad0[0x1b0c];
    float f1b0c;
    float f1b10;
    float f1b14;
    char pad1b18[0x1b28 - 0x1b18];
    int f1b28;
    float FUN_00036090();
};

struct Obj54_cbc40 {
    Probe_cbc40 *FUN_00086340();
};
struct World {
    char pad0[0x54];
    Obj54_cbc40 *f54;
};

class Panel_cbc40 {
public:
    char pad0[0x14];
    Pawn_cbc40 *p14;
    char pad18[0x14c - 0x18];
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    int f160;
    char pad164[4];
    UiVec_cbc40 *p168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    char pad198[4];
    UiVec_cbc40 *p19c;
    int state;
    void FUN_000caa60(const char *a, int *b);
    void FUN_000cbc40(float dt);
};

void Panel_cbc40::FUN_000cbc40(float dt)
{
    if (p14 == 0)
        return;
    f154 = p14->f1b0c;
    float t;
    t = f154 - f158;
    if (t < 0.0f)
        t = -t;
    if (!(t <= 1e-05f)) {
        t = f14c - f150;
        if (t < 0.0f)
            t = -t;
        if (t <= 1e-05f)
            f15c = 0.0f;
        if (f15c > 0.5f)
            FUN_000cb7d0(&f158, &f154, dt * 200.0f);
    }

    float a = p14->f1b0c;
    f174 = a - p14->FUN_00036090();
    t = f174 - f178;
    if (t < 0.0f)
        t = -t;
    if (!(t <= 1e-05f)) {
        t = f16c - f170;
        if (t < 0.0f)
            t = -t;
        if (t <= 1e-05f)
            f180 = 0.0f;
        if (f180 > 0.5f)
            FUN_000cb7d0(&f178, &f174, dt * 100.0f);
    }

    f18c = p14->f1b0c;
    t = f18c - f190;
    if (t < 0.0f)
        t = -t;
    if (!(t <= 1e-05f)) {
        t = f184 - f188;
        if (t < 0.0f)
            t = -t;
        if (t <= 1e-05f)
            f194 = 0.0f;
        if (f194 > 0.5f)
            FUN_000cb7d0(&f190, &f18c, dt * 100.0f);
    }

    f15c = dt + f15c;
    f180 = dt + f180;
    f194 = dt + f194;

    t = f154 - f158;
    if (t < 0.0f)
        t = -t;
    bool settled = false;
    if (t <= 1e-05f) {
        settled = true;
        if (state == 1) {
            t = f174 - f178;
            if (t < 0.0f)
                t = -t;
            if (!(t <= 1e-05f))
                settled = false;
        }
    }
    if (settled) {
        if (f160 < 0xff) {
            char zero = 0;
            FUN_000caa60(&zero, &f160);
        }
    } else {
        FUN_000caa60(&DAT_004dde78, &f160);
    }
    f14c = f154;
    f150 = f158;
    f16c = f174;
    f170 = f178;
    f184 = f18c;
    f188 = f190;

    struct Frame {
        int pad0;
        union {
            float f;
            int i;
            Probe_cbc40 *p;
        } w[8];                 // w[1] = base+0x14 ... w[8] = base+0x30 (indexes 1..7 used)
    };
    Frame f;
    bool bl = false;
    f.w[2].f = 0.0f;            // A
    f.w[1].f = 0.0f;            // B
    f.w[3].p = DAT_004dd700->f54->FUN_00086340();
    int st = state;
    bool doLists = true;
    if (st == 0) {
        int m = p14->f1b28;
        if (m == 1) {
            state = 4;
            bl = true;
            f.w[2].f = 0.0f;
            f.w[1].f = 25.0f;
            if (f.w[3].p->FUN_00092940(0x28b)) {
                f.w[1].f = 40.0f;
                if (f.w[3].p->FUN_00092940(0x29e))
                    f.w[1].f = 60.0f;
            }
        } else if (m == 2) {
            state = 6;
            bl = true;
            f.w[2].f = 0.0f;
            f.w[1].f = 15.0f;
        }
        f178 = f174;
        f190 = f18c;
        if (!bl)
            doLists = false;
    } else if (st == 1) {
        dt = dt * 1000.0f;
        int n = (unsigned char)(p19c->end - p19c->begin);
        for (int i = 0; i < n; i++)
            p19c->begin[(unsigned char)i]->v6(dt, 1);
        if (p14->f1b28 == 1) {
            doLists = false;
        } else {
            state = 3;
            f.w[2].f = 100.0f;
            f.w[1].f = 135.0f;
            if (f.w[3].p->FUN_00092940(0x28b)) {
                f.w[2].f = 80.0f;
                if (f.w[3].p->FUN_00092940(0x29e))
                    f.w[2].f = 60.0f;
            }
        }
    } else if (st == 2) {
        dt = dt * 1000.0f;
        int n = (unsigned char)(p19c->end - p19c->begin);
        for (int i = 0; i < n; i++)
            p19c->begin[(unsigned char)i]->v6(dt, 1);
        if (p14->f1b28 == 2) {
            doLists = false;
        } else {
            state = 5;
            f.w[2].f = 120.0f;
            f.w[1].f = 135.0f;
        }
    } else if (st == 3) {
        float *ms = &f.w[4].f;
        int *n = &f.w[5].i;
        float *hi = &f.w[3].f;
        float *lo = &f.w[6].f;
        float *val = &f.w[7].f;
        *ms = dt * 1000.0f;
        *n = (unsigned char)(p19c->end - p19c->begin);
        *(int *)&dt = 0;
        f17c = 0.0f;
        if (*n > 0) {
            *hi = 1.0f;
            *lo = 0.0f;
            for (int i = 0; i < *n; i++) {
                UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
                o->v6(*ms, 1);
                *val = (o->v13() - 120.0f) * 0.0666667f;
                f17c = FUN_000186b0(val, lo, hi);
                if (o->v22())
                    (*(int *)&dt)++;
            }
        }
        int n2 = (unsigned char)(p168->end - p168->begin);
        int cB = 0;
        for (int i = 0; i < n2; i++) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v6(*ms, 1);
            if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                cB++;
        }
        if (*(int *)&dt != *n || cB != n2) {
            doLists = false;
        } else {
            state = 0;
            f.w[2].f = 0.0f;
            f.w[1].f = 0.0f;
        }
    } else if (st == 4) {
        float *ms = &f.w[5].f;
        int *n = &f.w[8].i;
        float *hi = &f.w[7].f;
        float *lo = &f.w[6].f;
        float *val = &f.w[4].f;
        *ms = dt * 1000.0f;
        *n = (unsigned char)(p19c->end - p19c->begin);
        *(int *)&dt = 0;
        f17c = 0.0f;
        if (*n > 0) {
            *hi = 1.0f;
            *lo = 0.0f;
            for (int i = 0; i < *n; i++) {
                UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
                o->v6(*ms, 1);
                *val = o->v13() * 0.0666667f;
                f17c = 1.0f - FUN_000186b0(val, lo, hi);
                if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                    (*(int *)&dt)++;
            }
        }
        int n2 = (unsigned char)(p168->end - p168->begin);
        int cB = 0;
        for (int i = 0; i < n2; i++) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v6(*ms, 1);
            if (o->v22())
                cB++;
        }
        if (*(int *)&dt != *n || cB != n2) {
            doLists = false;
        } else {
            state = 1;
            f178 = 0.0f;
            f.w[2].f = 25.0f;
            f.w[1].f = 25.0f;
            if (f.w[3].p->FUN_00092940(0x28b)) {
                f.w[2].f = 40.0f;
                f.w[1].f = 40.0f;
                if (f.w[3].p->FUN_00092940(0x29e)) {
                    f.w[2].f = 60.0f;
                    f.w[1].f = 60.0f;
                }
            }
        }
    } else if (st == 5 || st == 6) {
        float *ms = &f.w[5].f;
        int *n = &f.w[3].i;
        float *hi = &f.w[8].f;
        float *lo = &f.w[7].f;
        float *val = &f.w[6].f;
        *ms = dt * 1000.0f;
        *n = (unsigned char)(p19c->end - p19c->begin);
        *(int *)&dt = 0;
        if (*n > 0) {
            *hi = 1.0f;
            *lo = 0.0f;
            for (int i = 0; i < *n; i++) {
                UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
                o->v6(*ms, 1);
                if (st == 5) {
                    *val = (o->v13() - 120.0f) * 0.0666667f;
                    f17c = FUN_000186b0(val, lo, hi);
                    if (o->v22())
                        (*(int *)&dt)++;
                } else {
                    *val = o->v13() * 0.0666667f;
                    f17c = 1.0f - FUN_000186b0(val, lo, hi);
                    if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                        (*(int *)&dt)++;
                }
            }
        }
        int n2 = (unsigned char)(p168->end - p168->begin);
        f.w[4].i = 0;
        for (int i = 0; i < n2; i++) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v6(*ms, 1);
            if (st == 5) {
                if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                    f.w[4].i++;
            } else {
                if (o->v22())
                    f.w[4].i++;
            }
        }
        if (*(int *)&dt != *n || f.w[4].i != n2) {
            doLists = false;
        } else if (st == 5) {
            state = 0;
            f.w[2].f = 0.0f;
            f.w[1].f = 0.0f;
        } else {
            state = 2;
            f.w[2].f = 15.0f;
            f.w[1].f = 15.0f;
        }
    } else {
        doLists = false;
    }
    if (doLists) {
        int n = (unsigned char)(p19c->end - p19c->begin);
        for (int i = 0; i < n; i = i) {
            UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
            o->v14(f.w[2].f, f.w[1].f);
            o->v12(f.w[2].f);
            n = (unsigned char)(p19c->end - p19c->begin);
            i++;
        }
        n = (unsigned char)(p168->end - p168->begin);
        for (int i = 0; i < n; i = i) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v14(f.w[2].f, f.w[1].f);
            o->v12(f.w[2].f);
            n = (unsigned char)(p168->end - p168->begin);
            i++;
        }
    }
}
