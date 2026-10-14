// STATUS: equivalent (tools/equiv.py level 3: 3046 inputs, branch coverage 90/95, incomplete)
// FUN_002dc3e0 @ 0x002dc3e0
extern "C" double __cdecl pow(double, double);
extern "C" double __cdecl fabs(double);

struct Col {
    unsigned char idx;
    unsigned char pad;
    unsigned short r;
    unsigned short g;
    unsigned short b;
    unsigned short gray;
};

struct Pal {
    char pad00[0x68];
    unsigned int flags;             // 0x68
    char pad6c[0x10c - 0x6c];
    unsigned char *entries;         // 0x10c, 3 bytes per entry
    unsigned short count;           // 0x110
    unsigned short alphaCount;      // 0x112
    char pad114[0x11e - 0x114];
    unsigned char mode;             // 0x11e
    unsigned char bits;             // 0x11f
    char pad120[0x128 - 0x120];
    unsigned char kind;             // 0x128
    char pad129[3];
    float f12c;
    Col cur;                        // 0x130
    Col out;                        // 0x13a
    char pad144[0x154 - 0x144];
    float f154;
    float f158;
    unsigned char *tab15c;
    unsigned char *tab160;
    unsigned char *tab164;
    char pad168[0x174 - 0x168];
    unsigned char sh0;              // 0x174
    unsigned char sh1;
    unsigned char sh2;
    char pad177[0x180 - 0x177];
    unsigned char *alpha;           // 0x180
};

void __cdecl FUN_002dbd90(Pal *p);

void FUN_002dc3e0(Pal *p)
{
    unsigned int mode = p->mode;
    unsigned int flags = p->flags;
    int i;

    if (flags & 0x100) {
        if (!(mode & 2)) {
            switch (p->bits) {
            case 1: {
                unsigned short g = (unsigned short)(p->cur.gray * 0xff);
                p->cur.gray = g;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            case 2: {
                unsigned short g = (unsigned short)(p->cur.gray * 0x55);
                p->cur.gray = g;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            case 4: {
                unsigned short g = (unsigned short)(p->cur.gray * 0x11);
                p->cur.gray = g;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            case 8:
            case 16: {
                unsigned short g = p->cur.gray;
                p->cur.b = g;
                p->cur.g = g;
                p->cur.r = g;
                break;
            }
            }
        } else if (mode == 3) {
            unsigned char *e = p->entries + p->cur.idx * 3;
            p->cur.r = e[0];
            p->cur.g = e[1];
            p->cur.b = e[2];
            if ((flags & 0x80000) && !(flags & 0x1000)) {
                int n = p->alphaCount;
                for (i = 0; i < n; i++)
                    p->alpha[i] = 0xff - p->alpha[i];
            }
        }
    }

    p->out = p->cur;

    flags = p->flags;
    if (flags & 0x602000) {
        FUN_002dbd90(p);
        if (p->flags & 0x80) {
            if (mode == 3) {
                int count = p->count;
                double A, B;
                unsigned char c0, c1, c2, d0, d1, d2;
                if (p->kind == 2) {
                    unsigned char *t = p->tab15c;
                    c0 = t[p->cur.r];
                    c1 = t[p->cur.g];
                    c2 = t[p->cur.b];
                    unsigned char *u = p->tab164;
                    d0 = u[p->cur.r];
                    d1 = u[p->cur.g];
                    d2 = u[p->cur.b];
                } else {
                    switch (p->kind) {
                    case 1:
                        A = p->f158;
                        B = 1.0;
                        break;
                    case 2:
                        A = 1.0 / p->f154;
                        B = 1.0 / ((double)p->f158 * p->f154);
                        break;
                    case 3:
                        A = 1.0 / p->f12c;
                        B = 1.0 / ((double)p->f158 * p->f12c);
                        break;
                    default:
                        A = 1.0;
                        B = 1.0;
                        break;
                    }
                    if (fabs(B - 1.0) < 0.05) {
                        c0 = (unsigned char)p->cur.r;
                        c1 = (unsigned char)p->cur.g;
                        c2 = (unsigned char)p->cur.b;
                    } else {
                        c0 = (unsigned char)(int)(pow(p->cur.r * 0.00392156862745098, B) * 255.0 + 0.5);
                        c1 = (unsigned char)(int)(pow(p->cur.g * 0.00392156862745098, B) * 255.0 + 0.5);
                        c2 = (unsigned char)(int)(pow(p->cur.b * 0.00392156862745098, B) * 255.0 + 0.5);
                    }
                    d0 = (unsigned char)(int)(pow(p->cur.r * 0.00392156862745098, A) * 255.0 + 0.5);
                    d1 = (unsigned char)(int)(pow(p->cur.g * 0.00392156862745098, A) * 255.0 + 0.5);
                    d2 = (unsigned char)(int)(pow(p->cur.b * 0.00392156862745098, A) * 255.0 + 0.5);
                }
                unsigned char *pal = p->entries;
                for (i = 0; i < count; i++) {
                    unsigned char *e = pal + i * 3;
                    if (i >= p->alphaCount || p->alpha[i] == 0xff) {
                        e[0] = p->tab15c[e[0]];
                        e[1] = p->tab15c[e[1]];
                        e[2] = p->tab15c[e[2]];
                    } else if (p->alpha[i] == 0) {
                        e[0] = c0;
                        e[1] = c1;
                        e[2] = c2;
                    } else {
                        unsigned int a = p->alpha[i];
                        unsigned int s = (unsigned short)(p->tab164[e[0]] * a + (0xff - a) * d0 + 0x80);
                        e[0] = p->tab160[(unsigned char)(((s >> 8) + s) >> 8)];
                        a = p->alpha[i];
                        s = (unsigned short)(p->tab164[e[1]] * a + (0xff - a) * d1 + 0x80);
                        e[1] = p->tab160[(unsigned char)(((s >> 8) + s) >> 8)];
                        a = p->alpha[i];
                        s = (unsigned short)(p->tab164[e[2]] * a + (0xff - a) * d2 + 0x80);
                        e[2] = p->tab160[(unsigned char)(((s >> 8) + s) >> 8)];
                    }
                }
            } else {
                unsigned int m = (1u << p->bits) - 1;
                double M = (double)m;
                double C0 = 1.0;
                double C1 = 1.0;
                switch (p->kind) {
                case 1:
                    C0 = p->f158;
                    C1 = 1.0;
                    break;
                case 2:
                    C0 = 1.0 / p->f154;
                    C1 = 1.0 / ((double)p->f158 * p->f154);
                    break;
                case 3:
                    C0 = 1.0 / p->f12c;
                    C1 = 1.0 / ((double)p->f158 * p->f12c);
                    break;
                }
                if (mode & 2) {
                    double inv = 1.0 / M;
                    double v1 = p->cur.r * inv;
                    p->out.r = (unsigned short)(int)(pow(v1, C0) * M + 0.5);
                    double v2 = p->cur.g * inv;
                    p->out.g = (unsigned short)(int)(pow(v2, C0) * M + 0.5);
                    double v3 = p->cur.b * inv;
                    p->out.b = (unsigned short)(int)(pow(v3, C0) * M + 0.5);
                    p->cur.r = (unsigned short)(int)(pow(v1, C1) * M + 0.5);
                    p->cur.g = (unsigned short)(int)(pow(v2, C1) * M + 0.5);
                    p->cur.b = (unsigned short)(int)(pow(v3, C1) * M + 0.5);
                } else {
                    double v = p->cur.gray / M;
                    p->out.gray = (unsigned short)(int)(pow(v, C0) * M + 0.5);
                    p->cur.gray = (unsigned short)(int)(pow(v, C1) * M + 0.5);
                }
            }
        } else if (mode == 3) {
            int n = p->count;
            if (n > 0) {
                unsigned char *e = p->entries;
                for (i = 0; i < n; i++) {
                    e[0] = p->tab15c[e[0]];
                    e[1] = p->tab15c[e[1]];
                    e[2] = p->tab15c[e[2]];
                    e += 3;
                }
            }
        }
    } else if ((flags & 0x80) && mode == 3) {
        int n = p->alphaCount;
        unsigned char r = (unsigned char)p->cur.r;
        unsigned char g = (unsigned char)p->cur.g;
        unsigned char b = (unsigned char)p->cur.b;
        if (n > 0) {
            unsigned char *e = p->entries;
            for (i = 0; i < n; i++) {
                unsigned int a = p->alpha[i];
                if (a == 0) {
                    e[0] = r;
                    e[1] = g;
                    e[2] = b;
                } else if (a != 0xff) {
                    unsigned int s = (unsigned short)((0xff - a) * r + e[0] * a + 0x80);
                    e[0] = (unsigned char)(((s >> 8) + s) >> 8);
                    a = p->alpha[i];
                    s = (unsigned short)((0xff - a) * g + e[1] * a + 0x80);
                    e[1] = (unsigned char)(((s >> 8) + s) >> 8);
                    a = p->alpha[i];
                    s = (unsigned short)((0xff - a) * b + e[2] * a + 0x80);
                    e[2] = (unsigned char)(((s >> 8) + s) >> 8);
                }
                e += 3;
            }
        }
    }

    if ((p->flags & 8) && mode == 3) {
        int s0 = 8 - p->sh0;
        int s1 = 8 - p->sh1;
        int s2 = 8 - p->sh2;
        unsigned short n = p->count;
        if (s0 < 0 || s0 > 8) s0 = 0;
        if (s1 < 0 || s1 > 8) s1 = 0;
        if (s2 < 0 || s2 > 8) s2 = 0;
        for (i = 0; i < n; i++) {
            p->entries[i * 3] >>= s0;
            p->entries[i * 3 + 1] >>= s1;
            p->entries[i * 3 + 2] >>= s2;
        }
    }
}
