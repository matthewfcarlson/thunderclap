// STATUS: equivalent (tools/equiv.py level 3: 1443 inputs, branch coverage 77/92, incomplete)
// FUN_00038660 @ 0x00038660
struct V3_38660 {
    float x, y, z;
    float FUN_0022d110();
};

struct Rng_38660 {
    int FUN_00011380(int a, int b);
};
Rng_38660 *FUN_000964d0();

struct Rc {
    char pad0[0xc];
    int f0c;
};

struct Sub74_38660 {
    char pad0[0x72];
    char b72;
};
struct Sub_38660 {
    char pad0[0x74];
    Sub74_38660 *p74;
};
struct Link_38660 {
    char pad0[0x74];
    Sub74_38660 *p74;
};
struct Ent_38660 {
    Sub_38660 *FUN_001d72e0();
};

struct Player_38660 {
    char pad0[0x124];
    void *f124;
};
struct Hub_38660 {
    char pad0[0x20];
    Player_38660 *p20;
};
extern Hub_38660 *DAT_004dd700;

struct Slot_38660 {
    float x0, y0, z0;
    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;
    Rc *ptr;
    char flag;
    char pad35[3];
};

struct Opts_38660 {
    float a;
    int flag;
    float c;
};

void FUN_000187d0(Rc **slot);
void FUN_00018810(Rc **slot, int z);
char FUN_00018960(float a, float b, float eps);
void FUN_00224d70(float angle, V3_38660 *v);
float FUN_00224f10(V3_38660 *v);
char FUN_00202560(V3_38660 *from, int a2, int flag, V3_38660 *a3, V3_38660 *a4, V3_38660 *o38, V3_38660 *o48, Opts_38660 *opts);
extern "C" int __cdecl FUN_0034483c();

class Mover_38660 {
public:
    char pad0[0x128];
    Ent_38660 *p128;
    Link_38660 *p12c;
    char pad130[0x334 - 0x130];
    void *f334;
    void *f338;
    char pad33c[0x1ea8 - 0x33c];
    Slot_38660 slots[3];
    void FUN_00035fa0(int z);
    char F(V3_38660 *a1, int a2, V3_38660 *a3, V3_38660 *a4, V3_38660 *a5, int *a6, int idx, char *a8, V3_38660 *a9);
};

char Mover_38660::F(V3_38660 *a1, int a2, V3_38660 *a3, V3_38660 *a4, V3_38660 *a5, int *a6, int idx, char *a8, V3_38660 *a9)
{
    struct Frame {
        Opts_38660 opts;
        V3_38660 D;
        V3_38660 Fp;
        V3_38660 o38;
        int pad44;
        V3_38660 o48;
    } fr;
    char result;
    char isPlayer;
    char *flagOut;

    if (p12c) {
        Sub74_38660 *x = p12c->p74;
        if (x)
            x->b72 = 0;
    }
    if (p128) {
        Sub_38660 *r = p128->FUN_001d72e0();
        if (r) {
            Sub74_38660 *y = r->p74;
            if (y)
                y->b72 = 0;
        }
    }
    FUN_00035fa0(0);
    if (idx >= 0 && idx < 3) {
        Slot_38660 *s = &slots[idx];
        if (s->flag != 0) {
            Rc *rc = s->ptr;
            if (rc != 0 && rc->f0c == 0) {
                s->flag = 0;
                FUN_000187d0(&s->ptr);
            }
        }
    }
    flagOut = a8;
    if (flagOut)
        *flagOut = 0;
    isPlayer = DAT_004dd700->p20->f124 == (void *)this;
    result = 1;
    float tol1 = 0.4f, tol0 = 0.4f, tol2 = 0.4f;
    if (isPlayer) {
        tol1 = 0.01f;
        tol0 = 0.01f;
        tol2 = 0.01f;
    }
    fr.opts.c = tol2;
    if (idx >= 0 && idx < 3 && slots[idx].flag) {
        Slot_38660 *s = &slots[idx];
        union { float f; unsigned int u; } t;
        t.f = a1->x - s->x0;
        t.u &= 0x7fffffff;
        if (t.f < tol1) {
            t.f = a1->y - s->y0;
            t.u &= 0x7fffffff;
            if (t.f < tol0) {
                t.f = a1->z - s->z0;
                t.u &= 0x7fffffff;
                if (t.f < tol2) {
                    a3->x = a1->x;
                    a3->y = a1->y;
                    a3->z = a1->z;
                    a3->y = s->y1;
                    a4->x = s->x2;
                    a4->y = s->y2;
                    a4->z = s->z2;
                    if (a5) {
                        a5->x = a1->x;
                        a5->y = a1->y;
                        a5->z = a1->z;
                        a5->y = s->y3;
                    }
                    if (a6)
                        *a6 = (int)slots[idx].ptr;
                    if (flagOut)
                        *flagOut = 1;
                    goto epilogue;
                }
            }
        }
    }
    {
        int notOwner = 0;
        void *pl = DAT_004dd700->p20->f124;
        if ((void *)this != pl && f338 != pl && f334 != pl)
            notOwner = 1;
        fr.opts.flag = notOwner;
        fr.o48.x = 0;
        fr.opts.a = 0;
        result = FUN_00202560(a1, a2, notOwner, a3, a4, &fr.o38, &fr.o48, &fr.opts);
        if (!result) {
            if (isPlayer && fr.opts.a == 0 && a9) {
                fr.Fp.x = a9->x;
                fr.Fp.y = a1->y;
                fr.Fp.z = a9->z;
                fr.D.x = a9->x - a1->x;
                fr.D.y = a1->y - a1->y;
                fr.D.z = a9->z - a1->z;
                float len = fr.D.FUN_0022d110();
                if (FUN_00018960(len, 0.0f, 1.0e-5f)) {
                    int r = FUN_000964d0()->FUN_00011380(0, 0xb);
                    unsigned int u = r;
                    float ang = (float)(((double)u + 0.5f) * 60.0f * 0.0174533f);
                    fr.D.x = 0;
                    fr.D.y = 0;
                    fr.D.z = -0.05f;
                    FUN_00224d70(ang, &fr.D);
                } else {
                    float a = FUN_00224f10(&fr.D) * 57.2958f * 0.0166667f;
                    int t = (int)a;
                    float frac = a - (float)t;
                    if (frac > 0.5f)
                        frac = frac - 1.0f;
                    if (FUN_00018960(frac, 0.0f, 0.25f))
                        FUN_00224d70(0.5236f, &fr.D);
                    fr.D.x = fr.D.x * 0.05f;
                    fr.D.y = fr.D.y * 0.05f;
                    fr.D.z = fr.D.z * 0.05f;
                }
                fr.Fp.x = a1->x + fr.D.x;
                fr.Fp.y = fr.D.y + a1->y;
                fr.Fp.z = a1->z + fr.D.z;
                result = FUN_00202560(&fr.Fp, a2, notOwner, a3, a4, &fr.o38, &fr.o48, &fr.opts);
                if (result) {
                    a3->x = a1->x;
                    a3->z = a1->z;
                    fr.o38.x = a1->x;
                    fr.o38.z = a1->z;
                    goto success;
                }
            }
            if (idx >= 0 && idx < 3)
                slots[idx].flag = 0;
            goto epilogue;
        }
    success:
        if (*(int *)&fr.o48.x == 0 && idx >= 0 && idx < 3) {
            Slot_38660 *s = &slots[idx];
            s->flag = 1;
            s->x0 = a1->x;
            s->y0 = a1->y;
            s->z0 = a1->z;
            s->x1 = a3->x;
            s->y1 = a3->y;
            s->z1 = a3->z;
            s->x2 = a4->x;
            s->y2 = a4->y;
            s->z2 = a4->z;
            s->x3 = fr.o38.x;
            s->y3 = fr.o38.y;
            s->z3 = fr.o38.z;
            FUN_00018810(&slots[idx].ptr, 0);
        }
        if (a5) {
            a5->x = fr.o38.x;
            a5->y = fr.o38.y;
            a5->z = fr.o38.z;
        }
        if (a6)
            *a6 = *(int *)&fr.o48.x;
    }
epilogue:
    FUN_00035fa0(1);
    if (p12c) {
        Sub74_38660 *x = p12c->p74;
        if (x)
            x->b72 = 1;
    }
    if (p128) {
        Sub_38660 *r = p128->FUN_001d72e0();
        if (r) {
            Sub74_38660 *y = r->p74;
            if (y)
                y->b72 = 1;
        }
    }
    return result;
}
