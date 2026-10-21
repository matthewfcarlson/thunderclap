// STATUS: equivalent (tools/equiv.py level 3: 19976 inputs, branch coverage 8/8)
// FUN_00079c80 @ 0x00079c80
#include "decls/data/game/global.h"
#include "compat/ptr.h"

struct Item_79c80 {
    float f0;
    float f4;
    float f8;
    float fc;
    char flag;
    char pad11[3];
};

struct Rec_79c80 {
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

class Mesh_79c80 {
public:
    char pad0[0x1904];
    Rec_79c80 recs[1];
    void FUN_00079c80(Item_79c80 *p, int i2, int i3, int i4, int a5, int a6, int a7, int *cnt, int v9, int v10);
};

void Mesh_79c80::FUN_00079c80(Item_79c80 *p, int i2, int i3, int i4, int a5, int a6, int a7, int *cnt, int v9, int v10)
{
    Item_79c80 *it2 = &p[i2];
    if (it2->flag == 0)
        return;
    volatile float f5 = (float)a5;
    volatile float la = a5 * DAT_004dd048 * 90.0f;
    volatile float l18 = a6 * DAT_004dd04c * 90.0f;
    hulk_freg x = it2->f0;
    hulk_freg w = 35.0f;
    Item_79c80 *it3 = &p[i3];
    if (it3->flag != 0) {
        w = 35.0f - (it3->f8 + it3->f8 + it3->f4 * 0.5f + it3->fc);
    } else {
        Item_79c80 *it4 = &p[i4];
        if (it4->flag != 0)
            w = 35.0f - (it4->f8 + it4->f8 + it4->f4 * 0.5f + it4->fc);
    }
    int k = a7 * 14;
    int na5 = -a5;
    volatile float l2c = na5 * w;
    volatile float q = (it2->f4 + it2->f8 + 3.0f) * i3 + x;
    volatile float l24 = -q;
    hulk_freg a = la;
    recs[*cnt + k].f10 = 0;
    recs[*cnt + k].f0c = a;
    recs[*cnt + k].f14 = l24 + l18;
    hulk_freg r = DAT_004dd048 * l2c + la;
    recs[*cnt + k].f00 = r;
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f08 = recs[*cnt + k].f14;
    recs[*cnt + k].f18 = v9;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = (i3 != 0) + 2;
    recs[*cnt + k].f44 = 1;
    *cnt = *cnt + 1;
    recs[*cnt + k].f10 = 0;
    hulk_freg t = (it2->f4 + it2->f8 + 3.0f) * f5;
    recs[*cnt + k].f00 = a;
    l24 = -(q - t);
    recs[*cnt + k].f04 = 0;
    recs[*cnt + k].f14 = l24 + l18;
    recs[*cnt + k].f0c = r;
    recs[*cnt + k].f08 = recs[*cnt + k].f14;
    recs[*cnt + k].f18 = v10;
    recs[*cnt + k].f28 = 0;
    recs[*cnt + k].f2c = 0;
    recs[*cnt + k].f30 = 0;
    recs[*cnt + k].f34 = 0;
    recs[*cnt + k].f38 = 0;
    recs[*cnt + k].f3c = 0;
    recs[*cnt + k].f40 = (i3 != 0) ? 2 : 3;
    recs[*cnt + k].f44 = 1;
    *cnt = *cnt + 1;
}
