// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 15/18, incomplete)
// FUN_0025d0f0 @ 0x0025d0f0
struct Source {
    char pad00[8];
    unsigned f08;
    unsigned char *base;
};

extern Source *DAT_004e5ce0;

struct Texture {
    char pad00[0xc];
    unsigned height;
    unsigned char *dst;
    unsigned flags;
    int state;
};

void FUN_0025d0f0(Texture *t, int length)
{
    unsigned flags = t->flags;
    unsigned h = t->height;
    unsigned n = (flags >> 4) & 0x1f;
    unsigned rowStep = h / n;
    Source *g = DAT_004e5ce0;
    unsigned char *end = g->base + length;
    unsigned bpp = (flags >> 0x1d) & 3;
    unsigned colStep = g->f08 / n;

    if ((flags & 0xf) == 0) {
        unsigned stride = n * bpp;
        if (n == 0) {
            t->state = 2;
            return;
        }
        unsigned rowOff = 0;
        unsigned colOff = 0;
        for (unsigned count = n; count != 0; count--) {
            unsigned char *dst = t->dst + rowOff + colStep;
            unsigned char *src = DAT_004e5ce0->base + colOff;
            while (src < end) {
                *(unsigned short *)dst = *(unsigned short *)src;
                src += stride;
                dst += bpp;
            }
            rowOff += rowStep;
            colOff += bpp;
        }
        t->state = 2;
        return;
    }

    unsigned stride = n * 4;
    unsigned off = 0;
    for (unsigned j = 0; j < n; j++) {
        unsigned char *dst = t->dst + off + colStep;
        unsigned char *src = DAT_004e5ce0->base + j * 4;
        while (src < end) {
            for (int k = 0; k < 9; k++) {
                *(unsigned *)dst = *(unsigned *)src;
                src += stride;
                dst += 4;
            }
        }
        off += rowStep;
    }
    t->state = 2;
}
