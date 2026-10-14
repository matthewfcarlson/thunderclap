// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00079f40 @ 0x00079f40
extern float DAT_004dd048;

struct Item_79f40 {
    float f0;
    float f4;
    float f8;
    float fc;
    char flag;
    char pad11[3];
};

struct Rec_79f40 {
    float f00;
    int f04;
    float f08;
    float f0c;
    int f10;
    float f14;
    int f18;
    char pad1c[0xc];
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    char f44;
    char pad45[3];
};

class Mesh_79f40 {
public:
    char pad0[0x1904];
    Rec_79f40 recs[1];
    void FUN_00079f40(Item_79f40 *p, int i2, int i3, int i4, int i5, int i6, int a7, int *cnt, int v9, int v10);
};

void Mesh_79f40::FUN_00079f40(Item_79f40 *p, int i2, int i3, int i4, int i5, int i6, int a7, int *cnt, int v9, int v10)
{
    Item_79f40 *e = &p[i2];
    if (e->flag == 0)
        return;
    float ten = 10.0f;
    volatile float v = 10.0f;
    Item_79f40 *t3 = &p[i3];
    Item_79f40 *t = 0;
    if (t3->flag != 0)
        t = t3;
    else if (p[5].flag != 0)
        t = &p[i4];
    if (t != 0)
        v = (t->f8 + t->f8 + t->f4 * 0.5f + t->fc) + 10.0f;
    float f = ten;
    Item_79f40 *u = &p[i5];
    if (u->flag != 0) {
        f = (u->f8 + u->f8 + u->f4 * 0.5f + u->fc) + 10.0f;
    } else {
        Item_79f40 *w = &p[i6];
        if (w->flag != 0)
            f = (w->f8 + w->f8 + w->f4 * 0.5f + w->fc) + 10.0f;
    }
    int k = a7 * 14;
    volatile float l = (v + 45.0f - 90.0f) * DAT_004dd048;
    float r = DAT_004dd048 * 90.0f - (f + 45.0f) * DAT_004dd048;
    float z = (e->f8 + 1.0f) * 1.5f + e->f4 * 0.5f;
    recs[*cnt + k].f0c = l;
    recs[*cnt + k].f10 = 0;
    recs[*cnt + k].f14 = z;
    recs[*cnt + k].f00 = r;
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f08 = z;
    recs[*cnt + k].f18 = v9;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = 2;
    recs[*cnt + k].f44 = 1;
    float z2 = z - (e->f8 + e->f4 + 3.0f);
    *cnt = *cnt + 1;
    recs[*cnt + k].f00 = l;
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f08 = z2;
    recs[*cnt + k].f0c = r;
    recs[*cnt + k].f10 = 0;
    recs[*cnt + k].f14 = z2;
    recs[*cnt + k].f18 = v10;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = 3;
    recs[*cnt + k].f44 = 1;
    *cnt = *cnt + 1;
}
