// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_00079990 @ 0x00079990
extern float DAT_004dd048;
extern float DAT_004dd04c;

struct Entry_79990 {
    float f0;
    float f4;
    float f8;
    float fc;
    char active;
    char pad11[3];
};

struct Rec_79990 {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    int f18;
    char pad1c[0xc];
    int f28;
    int f2c;
    int f30[4];
    int f40;
    char f44;
    char pad45[3];
};

class Stage_79990 {
public:
    char pad0[0x1904];
    Rec_79990 recs[256];

    void FUN_00079990(Entry_79990 *tab, int a2, int a3, int a4, int a5, int a6, int a7, int *counter, int a9, int a10);
};

void Stage_79990::FUN_00079990(Entry_79990 *tab, int a2, int a3, int a4, int a5, int a6, int a7, int *counter, int a9, int a10)
{
    Entry_79990 *a = &tab[a2];
    if (!a->active)
        return;

    float aBits = a->f0;
    float l1 = (float)((double)a5 * DAT_004dd048 * 90.0f);
    float l2 = (float)((double)DAT_004dd04c * a6);
    float l3 = (float)((double)DAT_004dd04c * a6 * 90.0f);

    Entry_79990 *x = &tab[a3];
    if (!x->active) {
        x = &tab[a4];
        if (!x->active)
            x = 0;
    }
    double v = 10.0f;
    if (x)
        v = (double)x->f8 * 2 + (double)x->f4 * 0.5f + x->fc + 10.0f;

    int parity = a2 % 2;
    double t = (double)a->f4 + a->f8 + 3.0f;
    float m = (float)(t * parity + aBits);

    double na = (double)(-a5) * DAT_004dd048;
    float n = (float)na;
    float p = (float)((double)l2 * m);
    float q = (float)(na * m + l1);
    float r = (float)((double)p + l3);

    Rec_79990 *r1 = &recs[*counter + a7 * 14];
    r1->f4 = 0;
    r1->f0 = q;
    r1->f8 = r;
    float w = (float)(a6 * v);
    r1->fc = r1->f0;
    r1->f10 = 0;
    r1->f14 = w;
    r1->f18 = a9;
    r1->f28 = 0;
    r1->f2c = 0;
    r1->f30[0] = 0;
    r1->f30[1] = 0;
    r1->f30[2] = 0;
    r1->f30[3] = 0;
    int first = 0;
    if (a2 == 0 || a2 == 1)
        first = 1;
    r1->f40 = first;
    r1->f44 = 1;
    ++*counter;

    int prod = a5 * a6;
    Rec_79990 *r2 = &recs[*counter + a7 * 14];
    double t2 = (double)a->f4 + a->f8 + 3.0f;
    r2->f10 = 0;
    double d = m - t2 * prod;
    float x1 = (float)(n * d);
    float x2 = (float)(l2 * d);
    r2->fc = x1 + l1;
    r2->f14 = x2 + l3;
    r2->f0 = r2->fc;
    r2->f4 = 0;
    r2->f8 = w;
    r2->f18 = a10;
    r2->f28 = 0;
    r2->f2c = 0;
    r2->f30[0] = 0;
    r2->f30[1] = 0;
    r2->f30[2] = 0;
    r2->f30[3] = 0;
    int second = 0;
    if (a2 != 0 && a2 != 1)
        second = 1;
    r2->f40 = second;
    r2->f44 = 1;
    ++*counter;
}
