// STATUS: equivalent (tools/equiv.py level 3: 3086 inputs, branch coverage 85/86, incomplete)
// FUN_0007bf80 @ 0x0007bf80
#include "compat/ptr.h"
struct V3_7bf80 {
    float x, y, z;
    char FUN_0022d2b0(const V3_7bf80 *other, float eps);
};

struct Rec_7bf80 {
    char pad0[0x18];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int cnt;
    int hist[4];
    int f40;
    char active;
    char pad45[3];
};

struct XObj_7bf80 {
    char pad0[0x14];
    int count;
    int FUN_00106160(int idx);
};

struct Obj18_7bf80 {
    XObj_7bf80 *FUN_00106210(int id);
};
struct P382c {
    char pad0[0x18];
    Obj18_7bf80 *p18;
};

struct Item_7bf80 {
    char pad0[0x10];
    int type;
    char pad14[0x20 - 0x14];
    int i20;
    char pad24[0x28 - 0x24];
    unsigned int f28;
    char pad2c[0x64 - 0x2c];
    V3_7bf80 v64;
    char pad70[0xbc - 0x70];
    int ibc;
    int ic0;
    int ic4;
    int ic8;
    int icc;
    char padd0[0xdc - 0xd0];
    V3_7bf80 vdc;
    void FUN_00080ea0(void *dst, void *src);
    void FUN_00080f20(int a);
    void FUN_00080cb0(int a);
    void FUN_00080f40(int a);
    void FUN_00080f00(int a);
    void FUN_00080f10(int a);
    void FUN_00080ef0(int a);
};

class Anim_7bf80 {
public:
    char pad0[0x1904];
    char recsRaw[0x354c - 0x1904];
    Item_7bf80 *items[8];
    char pad356c[0x382c - 0x356c];
    P382c *p382c;
    int FUN_0007a200(int a);
    void FUN_0007afb0(int g, int to, int slot, int icc, void *out1, void *out2);
    Rec_7bf80 *R(int i) { return (Rec_7bf80 *)(recsRaw) + i; }
    void F(int idx);
};

void Anim_7bf80::F(int idx)
{
    struct Frame {
        int pa[3];
        int pb[3];
    } fr;
    Item_7bf80 *it = items[idx];
    if (it->type != 1)
        return;
    if (!it->v64.FUN_0022d2b0(&it->vdc, 0.3f))
        return;
    if (it->ibc < 0) {
        int ic0 = it->ic0;
        Obj18_7bf80 *o = p382c->p18;
        int ic8 = it->ic8;
        XObj_7bf80 *x = o->FUN_00106210(ic0);
        if (x) {
            int nxt;
            if (it->icc == 0) {
                nxt = (ic8 + 1) % x->count;
            } else {
                int cnt = x->count;
                nxt = (cnt + ic8 - 1) % cnt;
            }
            hulk_intptr v = x->FUN_00106160(nxt);
            it->FUN_00080ea0(&it->vdc, (void *)v);
            it->FUN_00080f20(nxt);
            return;
        }
        it->i20 = 0;
        it->FUN_00080cb0(0xc);
        return;
    }
    int g = FUN_0007a200(it->ibc);
    int ic0 = it->ic0;
    int ic8 = it->ic8;
    int ic4 = it->ic4;
    int base = g * 14;
    Rec_7bf80 *rec = R(ic0 + base);
    int s2 = rec->f18;
    int icc = it->icc;
    int s1 = rec->f40;
    int ebx = ic4;
    int edi2;
    if (ic4 != -1) {
        FUN_0007afb0(g, ic4, ic8, icc, fr.pb, fr.pa);
        if ((it->f28 >> 4) & 1) {
            it->FUN_00080ea0(&it->v64, fr.pb);
            it->FUN_00080f40(0);
            return;
        }
        it->FUN_00080ea0(fr.pb, fr.pa);
        it->FUN_00080f00(ic4);
        it->FUN_00080f10(-1);
        rec->cnt--;
        rec->hist[ic8]--;
        Rec_7bf80 *r2 = R(ic4 + base);
        r2->cnt++;
        r2->hist[ic8]++;
        return;
    }
    bool have = true;
    bool skip = false;
    if (s1 > 3) {
        have = false;
    } else if (s1 == 0) {
        if (s2 > 3) {
            have = false;
        } else if (s2 == 0) {
            if (icc != 0) skip = true; else { fr.pa[0] = 4; fr.pa[1] = 2; fr.pa[2] = 2; fr.pb[0] = 3; fr.pb[1] = 0; fr.pb[2] = 2; }
        } else if (s2 == 1) {
            if (icc != 0) skip = true; else { fr.pa[0] = 3; fr.pa[1] = 3; fr.pa[2] = 5; fr.pb[0] = 3; fr.pb[1] = 0; fr.pb[2] = 2; }
        } else if (s2 == 2) {
            if (icc == 0) skip = true; else { fr.pa[0] = 5; fr.pa[1] = 0; fr.pa[2] = 0; fr.pb[0] = 2; fr.pb[1] = 0; fr.pb[2] = 2; }
        } else {
            if (icc == 0) skip = true; else { fr.pa[0] = 1; fr.pa[1] = 1; fr.pa[2] = 4; fr.pb[0] = 2; fr.pb[1] = 0; fr.pb[2] = 3; }
        }
    } else if (s1 == 1) {
        if (s2 > 3) {
            have = false;
        } else if (s2 == 0) {
            if (icc != 0) skip = true; else { fr.pa[0] = 2; fr.pa[1] = 2; fr.pa[2] = 4; fr.pb[0] = 2; fr.pb[1] = 1; fr.pb[2] = 3; }
        } else if (s2 == 1) {
            if (icc != 0) skip = true; else { fr.pa[0] = 5; fr.pa[1] = 3; fr.pa[2] = 3; fr.pb[0] = 2; fr.pb[1] = 1; fr.pb[2] = 3; }
        } else if (s2 == 2) {
            if (icc == 0) skip = true; else { fr.pa[0] = 0; fr.pa[1] = 0; fr.pa[2] = 5; fr.pb[0] = 3; fr.pb[1] = 1; fr.pb[2] = 2; }
        } else {
            if (icc == 0) skip = true; else { fr.pa[0] = 4; fr.pa[1] = 1; fr.pa[2] = 1; fr.pb[0] = 1; fr.pb[1] = 1; fr.pb[2] = 2; }
        }
    } else {
        if (s2 > 5) {
            have = false;
        } else if (s2 == 0) {
            if (icc != 0) skip = true; else { fr.pa[0] = 2; fr.pa[1] = 4; fr.pa[2] = 2; fr.pb[0] = 1; fr.pb[1] = 3; fr.pb[2] = 0; }
        } else if (s2 == 1) {
            if (icc != 0) skip = true; else { fr.pa[0] = 3; fr.pa[1] = 5; fr.pa[2] = 3; fr.pb[0] = 0; fr.pb[1] = 2; fr.pb[2] = 1; }
        } else if (s2 == 2) {
            if (icc == 0) skip = true; else { fr.pa[0] = 0; fr.pa[1] = 5; fr.pa[2] = 0; fr.pb[0] = 1; fr.pb[1] = 2; fr.pb[2] = 0; }
        } else if (s2 == 3) {
            if (icc == 0) skip = true; else { fr.pa[0] = 1; fr.pa[1] = 4; fr.pa[2] = 1; fr.pb[0] = 0; fr.pb[1] = 3; fr.pb[2] = 1; }
        } else if (s2 == 4) {
            if (icc == 0) { fr.pa[0] = 3; fr.pa[1] = 3; fr.pa[2] = 3; fr.pb[0] = 1; fr.pb[1] = 3; fr.pb[2] = 0; }
            else { fr.pa[0] = 0; fr.pa[1] = 0; fr.pa[2] = 0; fr.pb[0] = 0; fr.pb[1] = 3; fr.pb[2] = 1; }
        } else {
            if (icc == 0) { fr.pa[0] = 2; fr.pa[1] = 2; fr.pa[2] = 2; fr.pb[0] = 0; fr.pb[1] = 2; fr.pb[2] = 1; }
            else { fr.pa[0] = 1; fr.pa[1] = 1; fr.pa[2] = 1; fr.pb[0] = 1; fr.pb[1] = 2; fr.pb[2] = 0; }
        }
    }
    if (skip) {
        edi2 = rec->f20;
        ebx = rec->f24;
        if (edi2 != g) {
            if (edi2 == -1)
                return;
            FUN_0007afb0(edi2, ebx, ic8, icc, fr.pa, fr.pb);
            it->FUN_00080ea0(&it->v64, fr.pb);
            it->FUN_00080ef0(R(edi2 * 14)->f1c);
            it->FUN_00080f00(ebx);
            rec->cnt--;
            rec->hist[ic8]--;
            Rec_7bf80 *r2 = R(edi2 * 14 + ebx);
            r2->cnt++;
            r2->hist[ic8]++;
            return;
        }
    }
    for (int k = 0; k < 3; k++) {
        if (ebx != -1)
            break;
        Rec_7bf80 *rj = R(base);
        for (int j = 0; j < 14; j++, rj++) {
            if (rj->active) {
                if (rj->f18 == fr.pa[k] && rj->f40 == fr.pb[k]) {
                    ebx = j;
                    break;
                }
            }
        }
    }
    if (ebx == -1)
        return;
    FUN_0007afb0(g, ebx, ic8, icc, fr.pb, fr.pa);
    it->FUN_00080ea0(&it->v64, fr.pb);
    it->FUN_00080f40(0);
    it->FUN_00080f10(ebx);
}
