// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 41/50, incomplete)
// FUN_002ec780 @ 0x002ec780
struct inflate_huft {
    unsigned char exop;
    unsigned char bits;
    unsigned short pad2;
    unsigned int base;
};

struct inflate_blocks_state {
    char pad00[0x1c];
    unsigned int bitk;
    unsigned int bitb;
    char pad24[4];
    unsigned char *window;
    unsigned char *end;
    unsigned char *read;
    unsigned char *write;
};

struct z_stream {
    unsigned char *next_in;
    unsigned int avail_in;
    unsigned int total_in;
    char pad0c[0x18 - 0x0c];
    const char *msg;
};

extern unsigned int DAT_004d2838[17];

// zlib inflate_fast
int __cdecl inflate_fast(unsigned int bl, unsigned int bd, inflate_huft *tl, inflate_huft *td,
                         inflate_blocks_state *s, z_stream *z)
{
    inflate_huft *t;
    unsigned int e;
    unsigned int b;
    unsigned int k;
    unsigned char *p;
    unsigned int n;
    unsigned char *q;
    unsigned int m;
    unsigned int ml;
    unsigned int md;
    unsigned int c;
    unsigned int d;
    unsigned char *r;

    p = z->next_in;
    n = z->avail_in;
    b = s->bitb;
    k = s->bitk;
    q = s->write;
    m = (unsigned int)(q < s->read ? s->read - q - 1 : s->end - q);

    ml = DAT_004d2838[bl];
    md = DAT_004d2838[bd];

    do {
        while (k < 20) {
            n--;
            b |= (unsigned int)(*p++) << k;
            k += 8;
        }
        if ((e = (t = tl + (b & ml))->exop) == 0) {
            b >>= t->bits;
            k -= t->bits;
            *q++ = (unsigned char)t->base;
            m--;
            continue;
        }
        do {
            b >>= t->bits;
            k -= t->bits;
            if (e & 16) {
                e &= 15;
                c = t->base + (b & DAT_004d2838[e]);
                b >>= e;
                k -= e;
                while (k < 15) {
                    n--;
                    b |= (unsigned int)(*p++) << k;
                    k += 8;
                }
                e = (t = td + (b & md))->exop;
                do {
                    b >>= t->bits;
                    k -= t->bits;
                    if (e & 16) {
                        e &= 15;
                        while (k < e) {
                            n--;
                            b |= (unsigned int)(*p++) << k;
                            k += 8;
                        }
                        d = t->base + (b & DAT_004d2838[e]);
                        b >>= e;
                        k -= e;
                        m -= c;
                        if ((unsigned int)(q - s->window) >= d) {
                            r = q - d;
                            *q++ = *r++;
                            c--;
                            *q++ = *r++;
                            c--;
                        } else {
                            e = d - (unsigned int)(q - s->window);
                            r = s->end - e;
                            if (c > e) {
                                c -= e;
                                do {
                                    *q++ = *r++;
                                } while (--e);
                                r = s->window;
                            }
                        }
                        do {
                            *q++ = *r++;
                        } while (--c);
                        break;
                    } else if ((e & 64) == 0) {
                        t += t->base;
                        e = (t += (b & DAT_004d2838[e]))->exop;
                    } else {
                        z->msg = "invalid distance code";
                        c = z->avail_in - n;
                        c = (k >> 3) < c ? k >> 3 : c;
                        n += c;
                        p -= c;
                        k -= c << 3;
                        s->bitb = b;
                        s->bitk = k;
                        z->avail_in = n;
                        z->total_in += (unsigned int)(p - z->next_in);
                        z->next_in = p;
                        s->write = q;
                        return -3;
                    }
                } while (1);
                break;
            }
            if ((e & 64) == 0) {
                t += t->base;
                if ((e = (t += (b & DAT_004d2838[e]))->exop) == 0) {
                    b >>= t->bits;
                    k -= t->bits;
                    *q++ = (unsigned char)t->base;
                    m--;
                    break;
                }
            } else if (e & 32) {
                c = z->avail_in - n;
                c = (k >> 3) < c ? k >> 3 : c;
                n += c;
                p -= c;
                k -= c << 3;
                s->bitb = b;
                s->bitk = k;
                z->avail_in = n;
                z->total_in += (unsigned int)(p - z->next_in);
                z->next_in = p;
                s->write = q;
                return 1;
            } else {
                z->msg = "invalid literal/length code";
                c = z->avail_in - n;
                c = (k >> 3) < c ? k >> 3 : c;
                n += c;
                p -= c;
                k -= c << 3;
                s->bitb = b;
                s->bitk = k;
                z->avail_in = n;
                z->total_in += (unsigned int)(p - z->next_in);
                z->next_in = p;
                s->write = q;
                return -3;
            }
        } while (1);
    } while (m >= 258 && n >= 10);

    c = z->avail_in - n;
    c = (k >> 3) < c ? k >> 3 : c;
    n += c;
    p -= c;
    k -= c << 3;
    s->bitb = b;
    s->bitk = k;
    z->avail_in = n;
    z->total_in += (unsigned int)(p - z->next_in);
    z->next_in = p;
    s->write = q;
    return 0;
}
