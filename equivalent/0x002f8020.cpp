// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 31/38, incomplete)
// FUN_002f8020 @ 0x002f8020
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Sub8_2f8020 {
    void FUN_0030e190(int v);
};

struct Q_2f8020 {
    char pad0[0x1ec];
    int f1ec;               // 0x1ec
    char pad1f0[4];
    unsigned char f1f4;     // 0x1f4
};

struct Body_2f8020 {
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7();
    virtual void b8();
    virtual Q_2f8020 *b9(int v);
};

struct Holder_2f8020 {
    char pad0[0x18];
    Body_2f8020 *body;             // 0x18
};

struct Obj1_2f8020 {
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3();
    virtual void o4(); virtual void o5();
    virtual int o6();
    char pad04[0x38 - 0x4];
    int f38;                // 0x38
    int f3c;                // 0x3c
    char pad40[0x48 - 0x40];
    int f48;                // 0x48
};

struct Rec_2f8020 {
    int f0;
    Obj1_2f8020 *o1;               // 0x04
    Holder_2f8020 *p1;             // 0x08
    Holder_2f8020 *p2;             // 0x0c
    int f1c;                // 0x10
    int f20;                // 0x14
    float f24;              // 0x18
    float f28;              // 0x1c
    float f2c;              // 0x20
    int f30;                // 0x24
    int flags;              // 0x28
    int f38;                // 0x2c
    int f3c;                // 0x30
    int f40;                // 0x34
    int f44;                // 0x38
    int f48;                // 0x3c
    int f4c;                // 0x40
};

struct List_2f8020 {
    Rec_2f8020 *begin;
    Rec_2f8020 *end;
};

struct Zone_2f8020 {
    char pad0[8];
    int f8;                 // 0x8
    int fc;                 // 0xc
    char pad10[0x74 - 0x10];
    Holder_2f8020 *f74;            // 0x74
    void FUN_002ef440(int v);
};

struct Core_2f8020 {
    virtual void c0(); virtual void c1(); virtual void c2();
    virtual void c3(List_2f8020 *l, int a);
    virtual void c4(List_2f8020 *l, int a);
    virtual int c5(Rec_2f8020 *r, int it);
    virtual int c6(Body_2f8020 *b84, int f1c, Body_2f8020 *b88, int f20, int *f38, float k, float len, Q_2f8020 **q1, Q_2f8020 **q2);
    char pad04[4];
    Sub8_2f8020 *obj8;             // 0x8
};

class Solver_2f8020 {
public:
    virtual void s0();
    virtual void s1();
    Core_2f8020 *core;             // 0x4
    List_2f8020 *list;             // 0x8
    Rec_2f8020 r;                  // 0xc
    char pad50[0x74 - 0x50];
    float f74;
    float f78;
    float f7c;
    float k;                // 0x80
    Body_2f8020 *o84;              // 0x84
    Body_2f8020 *o88;              // 0x88
    Q_2f8020 *q1;                  // 0x8c
    Q_2f8020 *q2;                  // 0x90
    char pad94[0xf0 - 0x94];
    char f0;                // 0xf0
    char f1;                // 0xf1
    char padf2[6];
    int iters;              // 0xf8
    Zone_2f8020 *zone;             // 0xfc
    void FUN_002f7b00();
    void FUN_002f8020(List_2f8020 *l, int unused, int a3);
};

void Solver_2f8020::FUN_002f8020(List_2f8020 *l, int unused, int a3)
{
    if (core->obj8 != 0)
        core->obj8->FUN_0030e190(a3);
    hulk_intptr n = l->end - l->begin;
    if (n == 0)
        return;
    list = l;
    core->c3(l, a3);
    int it = 0;
    f1 = 1;
    do {
        f0 = 1;
        Rec_2f8020 *cur = list->begin;
        if (cur != list->end) {
            do {
                if ((cur->flags & 1) == 0) {
                    r = *cur;
                    if (r.o1->o6() == 4) {
                        Zone_2f8020 *z = zone;
                        Obj1_2f8020 *o = r.o1;
                        r.p2 = z->f74;
                        z->FUN_002ef440(o->f48);
                        Obj1_2f8020 *o2 = r.o1;
                        zone->fc = o2->f38;
                        zone->f8 = o2->f3c;
                    }
                    if (core->c5(&r, it + 1) == 1) {
                        cur->flags = cur->flags | 1;
                    } else {
                        Body_2f8020 *b84 = r.p1->body;
                        Body_2f8020 *b88 = r.p2->body;
                        o84 = b84;
                        o88 = b88;
                        Q_2f8020 *a = b84->b9(r.f1c);
                        q1 = a;
                        Q_2f8020 *b = o88->b9(r.f20);
                        Q_2f8020 *qa = q1;
                        q2 = b;
                        if (qa != 0) {
                            int t = qa->f1ec;
                            if (t == 0)
                                qa->f1ec = (hulk_intptr)r.p2;
                            else if (t != (hulk_intptr)r.p2)
                                qa->f1f4 = qa->f1f4 & 0xfe;
                        }
                        if (b != 0) {
                            int t = b->f1ec;
                            if (t == 0)
                                b->f1ec = (hulk_intptr)r.p1;
                            else if (t != (hulk_intptr)r.p1)
                                b->f1f4 = b->f1f4 & 0xfe;
                        }
                        FUN_002f7b00();
                        bool hit = false;
                        if (f1 != 0) {
                            double nk = -k;
                            double X = nk * r.f24 + f74;
                            double Y = nk * r.f28 + f78;
                            double Z = nk * r.f2c + f7c;
                            float len = (float)sqrt(X * X + (Y * Y + Z * Z));
                            if (core->c6(o84, r.f1c, o88, r.f20, &r.f38, k, len, &q1, &q2) == 1) {
                                cur->flags = cur->flags | 1;
                                hit = true;
                            }
                        }
                        if (!hit) {
                            if (q1 == 0 && q2 == 0) {
                                cur->flags = cur->flags | 1;
                            } else {
                                s1();
                                cur->flags = r.flags;
                            }
                        }
                    }
                }
                cur = cur + 1;
            } while (cur != list->end);
        }
        char done = f0;
        it++;
        f1 = 0;
        if (done != 0)
            break;
    } while (it < iters);
    core->c4(list, 0);
}
