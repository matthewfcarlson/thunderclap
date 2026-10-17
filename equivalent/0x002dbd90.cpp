// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 62/80, incomplete)
// FUN_002dbd90 @ 0x002dbd90
#include "decls/data/engine/pure3d.h"

extern "C" double __cdecl pow(double, double);

struct Gamma {
    char pad00[0x68];
    unsigned int flags;
    char pad6c[0x11e - 0x6c];
    unsigned char b11e;
    unsigned char mode;
    char pad120[0x150 - 0x120];
    unsigned int bits;
    float gamma;
    float scale;
    unsigned char *tab0;
    unsigned char *tab1;
    unsigned char *tab2;
    unsigned short **ptabA;
    unsigned short **ptabB;
    unsigned short **ptabC;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
};

unsigned char *__cdecl FUN_002e6c00(Gamma *g, unsigned int size);

void FUN_002dbd90(Gamma *g)
{
    if (g->gamma == 0.0)
        return;
    if (g->mode <= 8) {
        double e;
        if (g->scale > 1e-6)
            e = 1.0 / (g->scale * g->gamma);
        else
            e = 1.0;
        g->tab0 = FUN_002e6c00(g, 0x100);
        for (int i = 0; i < 0x100; i++)
            g->tab0[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e) * 255.0 + 0.5);
        if (!(g->flags & 0x600080))
            return;
        double e2 = 1.0 / g->gamma;
        g->tab2 = FUN_002e6c00(g, 0x100);
        for (int i = 0; i < 0x100; i++)
            g->tab2[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e2) * 255.0 + 0.5);
        g->tab1 = FUN_002e6c00(g, 0x100);
        double e3;
        if (g->scale > 1e-6)
            e3 = 1.0 / g->scale;
        else
            e3 = g->gamma;
        for (int i = 0; i < 0x100; i++)
            g->tab1[i] = (unsigned char)(int)(pow(i * 0.00392156862745098, e3) * 255.0 + 0.5);
        return;
    }

    int c;
    if (g->b11e & 2) {
        c = g->c0;
        if (g->c1 > c)
            c = g->c1;
        if (g->c2 > c)
            c = g->c2;
    } else {
        c = g->c3;
    }
    int bits;
    if (c > 0)
        bits = 0x10 - c;
    else
        bits = 0;
    if ((g->flags & 0x400) && bits < 5)
        bits = 5;
    else if (bits > 8)
        bits = 8;
    else if (bits < 0)
        bits = 0;
    g->bits = (unsigned char)bits;
    int shift = 8 - bits;
    int count = 1 << shift;
    double d;
    if (g->scale > 1e-6)
        d = 1.0 / (g->scale * g->gamma);
    else
        d = 1.0;
    g->ptabA = (unsigned short **)FUN_002e6c00(g, count * 4);
    unsigned int edi = 0;
    if (g->flags & 0x480) {
        for (int i = 0; i < count; i++)
            g->ptabA[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
        double invd = 1.0 / d;
        unsigned int n = count << 8;
        double dn = (double)n;
        edi = 0;
        for (int j = 0; j < 0x100; j++) {
            unsigned int end = (unsigned int)(int)(pow((j + 0.5) * 0.00390625, invd) * dn);
            if (!(edi > end)) {
                unsigned short v = (unsigned short)((j << 8) | j);
                int mask = 0xff >> bits;
                do {
                    g->ptabA[mask & edi][edi >> shift] = v;
                    edi++;
                } while (edi <= end);
            }
        }
        if (edi < n) {
            int mask = 0xff >> bits;
            do {
                g->ptabA[mask & edi][edi >> shift] = 0xffff;
                edi++;
            } while (edi < n);
        }
    } else {
        if (count > 0) {
            int i = 0;
            do {
                g->ptabA[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
                unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
                unsigned int k = 0;
                do {
                    g->ptabA[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, d) * 65535.0 + 0.5);
                    k += 2;
                    base += 0x100;
                } while (k < 0x200);
                i++;
            } while (i < count);
        }
    }
    if (!(g->flags & 0x600080))
        return;
    double e4 = 1.0 / g->gamma;
    g->ptabC = (unsigned short **)FUN_002e6c00(g, count * 4);
    if (count > 0) {
        int i = 0;
        do {
            g->ptabC[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
            unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
            unsigned int k = 0;
            do {
                g->ptabC[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, e4) * 65535.0 + 0.5);
                k += 2;
                base += 0x100;
            } while (k < 0x200);
            i++;
        } while (i < count);
    }
    double e5;
    if (g->scale > 1e-6)
        e5 = 1.0 / g->scale;
    else
        e5 = g->gamma;
    g->ptabB = (unsigned short **)FUN_002e6c00(g, count * 4);
    if (count > 0) {
        int i = 0;
        do {
            g->ptabB[i] = (unsigned short *)FUN_002e6c00(g, 0x200);
            unsigned int base = (((unsigned int*)&DAT_004d1164)[bits] * i) >> 4;
            unsigned int k = 0;
            do {
                g->ptabB[i][k / 2] = (unsigned short)(int)(pow((double)base * 1.5259021896696422e-05, e5) * 65535.0 + 0.5);
                k += 2;
                base += 0x100;
            } while (k < 0x200);
            i++;
        } while (i < count);
    }
}
