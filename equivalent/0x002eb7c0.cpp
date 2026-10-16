// STATUS: equivalent (tools/equiv.py level 3: 220 inputs, branch coverage 100/114, incomplete)
// FUN_002eb7c0 @ 0x002eb7c0
#include "decls/data/engine/physics.h"

typedef unsigned char Byte;
typedef Byte Bytef;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct inflate_huft {
    Byte exop;
    Byte bits;
    unsigned short pad;
    uInt base;
};

struct inflate_codes_state {
    int mode;                        // 0
    uInt len;                        // 4
    union {
        struct {
            inflate_huft *tree;      // 8
            uInt need;               // 0xc
        } code;
        uInt lit;
        struct {
            uInt get;
            uInt dist;
        } copy;
    } sub;
    Byte lbits;                      // 0x10
    Byte dbits;                      // 0x11
    inflate_huft *ltree;             // 0x14
    inflate_huft *dtree;             // 0x18
};

struct z_stream {
    Bytef *next_in;                  // 0
    uInt avail_in;                   // 4
    uLong total_in;                  // 8
    char pad_c[0x18 - 0xc];
    char *msg;                       // 0x18
};

struct inflate_blocks_state {
    int mode;                        // 0
    inflate_codes_state *codes;      // 4
    char pad8[0x1c - 8];
    uInt bitk;                       // 0x1c
    uLong bitb;                      // 0x20
    char pad24[4];
    Bytef *window;                   // 0x28
    Bytef *end;                      // 0x2c
    Bytef *read;                     // 0x30
    Bytef *write;                    // 0x34
};

        // inflate_mask
int __cdecl FUN_002ec780(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_state *s, z_stream *z);
int __cdecl FUN_002ec650(inflate_blocks_state *s, z_stream *z, int r);

#define LOAD { p = z->next_in; n = z->avail_in; b = s->bitb; k = s->bitk; q = s->write; m = (uInt)(q < s->read ? s->read - q - 1 : s->end - q); }
#define UPDATE { s->bitb = b; s->bitk = k; z->avail_in = n; z->total_in += p - z->next_in; z->next_in = p; s->write = q; }
#define LEAVE { UPDATE return FUN_002ec650(s, z, r); }
#define NEEDBITS(j) { while (k < (j)) { { if (n) r = 0; else LEAVE } n--; b |= ((uLong)(*p++)) << k; k += 8; } }
#define DUMPBITS(j) { b >>= (j); k -= (j); }
#define WRAP { if (q == s->end && s->read != s->window) { q = s->window; m = (uInt)(q < s->read ? s->read - q - 1 : s->end - q); } }
#define FLUSH { s->write = q; r = FUN_002ec650(s, z, r); q = s->write; m = (uInt)(q < s->read ? s->read - q - 1 : s->end - q); }
#define NEEDOUT { if (m == 0) { WRAP if (m == 0) { FLUSH WRAP if (m == 0) LEAVE } } r = 0; }
#define OUTBYTE(a) { *q++ = (Byte)(a); m--; }

int __cdecl FUN_002eb7c0(inflate_blocks_state *s, z_stream *z, int r)
{
    uInt j;
    inflate_huft *t;
    uInt e;
    uLong b;
    uInt k;
    Bytef *p;
    uInt n;
    Bytef *q;
    uInt m;
    Bytef *f;
    inflate_codes_state *c = s->codes;

    LOAD

    while (1) switch (c->mode) {
    case 0:
        if (m >= 258 && n >= 10) {
            UPDATE
            r = FUN_002ec780(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
            LOAD
            if (r != 0) {
                c->mode = r == 1 ? 7 : 9;
                break;
            }
        }
        c->sub.code.need = c->lbits;
        c->sub.code.tree = c->ltree;
        c->mode = 1;
    case 1:
        j = c->sub.code.need;
        NEEDBITS(j)
        t = c->sub.code.tree + ((uInt)b & ((uInt*)&DAT_004d2838)[j]);
        DUMPBITS(t->bits)
        e = (uInt)(t->exop);
        if (e == 0) {
            c->sub.lit = t->base;
            c->mode = 6;
            break;
        }
        if (e & 16) {
            c->sub.copy.get = e & 15;
            c->len = t->base;
            c->mode = 2;
            break;
        }
        if ((e & 64) == 0) {
            c->sub.code.need = e;
            c->sub.code.tree = t + t->base;
            break;
        }
        if (e & 32) {
            c->mode = 7;
            break;
        }
        c->mode = 9;
        z->msg = (char *)"invalid literal/length code";
        r = -3;
        LEAVE
    case 2:
        j = c->sub.copy.get;
        NEEDBITS(j)
        c->len += (uInt)b & ((uInt*)&DAT_004d2838)[j];
        DUMPBITS(j)
        c->sub.code.need = c->dbits;
        c->sub.code.tree = c->dtree;
        c->mode = 3;
    case 3:
        j = c->sub.code.need;
        NEEDBITS(j)
        t = c->sub.code.tree + ((uInt)b & ((uInt*)&DAT_004d2838)[j]);
        DUMPBITS(t->bits)
        e = (uInt)(t->exop);
        if (e & 16) {
            c->sub.copy.get = e & 15;
            c->sub.copy.dist = t->base;
            c->mode = 4;
            break;
        }
        if ((e & 64) == 0) {
            c->sub.code.need = e;
            c->sub.code.tree = t + t->base;
            break;
        }
        c->mode = 9;
        z->msg = (char *)"invalid distance code";
        r = -3;
        LEAVE
    case 4:
        j = c->sub.copy.get;
        NEEDBITS(j)
        c->sub.copy.dist += (uInt)b & ((uInt*)&DAT_004d2838)[j];
        DUMPBITS(j)
        c->mode = 5;
    case 5:
        f = (uInt)(q - s->window) < c->sub.copy.dist ? s->end - (c->sub.copy.dist - (q - s->window)) : q - c->sub.copy.dist;
        while (c->len) {
            NEEDOUT
            OUTBYTE(*f++)
            if (f == s->end)
                f = s->window;
            c->len--;
        }
        c->mode = 0;
        break;
    case 6:
        NEEDOUT
        OUTBYTE(c->sub.lit)
        c->mode = 0;
        break;
    case 7:
        if (k > 7) {
            k -= 8;
            n++;
            p--;
        }
        s->write = q;
        r = FUN_002ec650(s, z, r);
        q = s->write;
        if (s->read != q)
            LEAVE
        c->mode = 8;
    case 8:
        r = 1;
        LEAVE
    case 9:
        r = -3;
        LEAVE
    default:
        r = -2;
        LEAVE
    }
}
