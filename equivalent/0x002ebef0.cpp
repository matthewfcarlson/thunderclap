// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 74/90, incomplete)
// FUN_002ebef0 @ 0x002ebef0
typedef unsigned char Byte;
typedef unsigned int uInt;

struct inflate_huft {
    union {
        struct {
            Byte Exop;
            Byte Bits;
        } what;
        uInt pad;
    } word;
    uInt base;
};

// equiv-conv: FUN_002ebef0 ecx eax stack stack stack stack stack stack stack stack
int FUN_002ebef0(uInt *b, uInt *m, uInt n, uInt s, const uInt *d, const uInt *e, inflate_huft **t,
                 inflate_huft *hp, uInt *hn, uInt *v)
{
    uInt a;
    uInt c[16];
    uInt f;
    int g;
    int h;
    uInt i;
    uInt j;
    int k;
    int l;
    uInt mask;
    uInt *p;
    inflate_huft *q;
    inflate_huft r;
    inflate_huft *u[15];
    int w;
    uInt x[16];
    uInt *xp;
    int y;
    uInt z;

    for (i = 0; i < 16; i++)
        c[i] = 0;
    p = b;
    i = n;
    do {
        c[*p++]++;
    } while (--i);
    if (c[0] == n) {
        *t = 0;
        *m = 0;
        return 0;
    }

    l = *m;
    for (j = 1; j <= 15; j++)
        if (c[j])
            break;
    k = j;
    if ((uInt)l < j)
        l = j;
    for (i = 15; i; i--)
        if (c[i])
            break;
    g = i;
    if ((uInt)l > i)
        l = i;
    *m = l;

    for (y = 1 << j; j < i; j++, y <<= 1)
        if ((y -= c[j]) < 0)
            return -3;
    if ((y -= c[i]) < 0)
        return -3;
    c[i] += y;

    x[1] = j = 0;
    p = c + 1;
    xp = x + 2;
    while (--i) {
        *xp++ = (j += *p++);
    }

    p = b;
    i = 0;
    do {
        if ((j = *p++) != 0)
            v[x[j]++] = i;
    } while (++i < n);
    n = x[g];

    x[0] = i = 0;
    p = v;
    h = -1;
    w = -l;
    u[0] = 0;
    q = 0;
    z = 0;

    for (; k <= g; k++) {
        a = c[k];
        while (a--) {
            while (k > w + l) {
                h++;
                w += l;
                z = g - w;
                z = z > (uInt)l ? l : z;
                if ((f = 1 << (j = k - w)) > a + 1) {
                    f -= a + 1;
                    xp = c + k;
                    if (j < z)
                        while (++j < z) {
                            if ((f <<= 1) <= *++xp)
                                break;
                            f -= *xp;
                        }
                }
                z = 1 << j;
                if (*hn + z > 1440)
                    return -4;
                u[h] = q = hp + *hn;
                *hn += z;
                if (h) {
                    x[h] = i;
                    r.word.what.Bits = (Byte)l;
                    r.word.what.Exop = (Byte)j;
                    j = i >> (w - l);
                    r.base = (uInt)(q - u[h - 1] - j);
                    u[h - 1][j] = r;
                } else
                    *t = q;
            }

            r.word.what.Bits = (Byte)(k - w);
            if (p >= v + n)
                r.word.what.Exop = 128 + 64;
            else if (*p < s) {
                r.word.what.Exop = (Byte)(*p < 256 ? 0 : 32 + 64);
                r.base = *p++;
            } else {
                r.word.what.Exop = (Byte)(e[*p - s] + 16 + 64);
                r.base = d[*p++ - s];
            }

            f = 1 << (k - w);
            for (j = i >> w; j < z; j += f)
                q[j] = r;

            for (j = 1 << (k - 1); i & j; j >>= 1)
                i ^= j;
            i ^= j;

            mask = (1 << w) - 1;
            while ((i & mask) != x[h]) {
                h--;
                w -= l;
                mask = (1 << w) - 1;
            }
        }
    }

    return y != 0 && g != 1 ? -5 : 0;
}
