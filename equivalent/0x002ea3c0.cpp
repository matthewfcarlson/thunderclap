// STATUS: equivalent (tools/equiv.py level 3: 19923 inputs, branch coverage 133/142, incomplete)
// FUN_002ea3c0 @ 0x002ea3c0
// FUN_002ea3c0 @ 0x002ea3c0
#include "decls/data/engine/physics.h"

typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct z_stream;
typedef void *(__cdecl *alloc_func)(void *opaque, uInt items, uInt size);
typedef void (__cdecl *free_func)(void *opaque, void *address);

struct inflate_huft {
    Byte exop;
    Byte bits;
    unsigned short pad;
    uInt base;
};

struct z_stream {
    Byte *next_in;
    uInt avail_in;
    uLong total_in;
    Byte *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    void *state;
    alloc_func zalloc;
    free_func zfree;
    void *opaque;
};

struct inflate_codes_state;

struct inflate_blocks_state {
    uInt mode;
    union {
        uInt left;
        struct {
            uInt table;
            uInt index;
            uInt *blens;
            uInt bb;
            inflate_huft *tb;
        } trees;
        struct {
            inflate_codes_state *codes;
        } decode;
    } sub;
    uInt last;
    uInt bitk;
    uLong bitb;
    inflate_huft *hufts;
    Byte *window;
    Byte *end;
    Byte *read;
    Byte *write;
};

extern "C" void *memcpy(void *, const void *, unsigned int);

extern int __cdecl FUN_002ec650(inflate_blocks_state *s, z_stream *z, int r);
extern int __cdecl FUN_002ec620(uInt *bl, uInt *bd, inflate_huft **tl, inflate_huft **td, z_stream *z);
extern inflate_codes_state *__cdecl FUN_002eb780(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, z_stream *z);
extern int __cdecl FUN_002ec3e0(uInt *c, uInt *bb, inflate_huft **tb, inflate_huft *hp, z_stream *z);
extern int __cdecl FUN_002ec490(uInt nl, uInt nd, uInt *c, uInt *bl, uInt *bd, inflate_huft **tl, inflate_huft **td, inflate_huft *hp, z_stream *z);
extern int __cdecl FUN_002eb7c0(inflate_blocks_state *s, z_stream *z, int r);
extern void __cdecl FUN_002ebed0(inflate_codes_state *c, z_stream *z);

#define LOADIN { p = z->next_in; n = z->avail_in; b = s->bitb; k = s->bitk; }
#define WAVAIL ((uInt)(q < s->read ? s->read - q - 1 : s->end - q))
#define LOADOUT { q = s->write; m = WAVAIL; }
#define LOAD { LOADIN LOADOUT }
// zlib's order: s and z may alias, so the stores must come in this order.
#define UPDATEIN { s->bitb = b; s->bitk = k; z->avail_in = n; z->total_in += p - z->next_in; z->next_in = p; }
#define UPDATEOUT { s->write = q; }
#define UPDATE { UPDATEIN UPDATEOUT }
#define LEAVE { UPDATE return FUN_002ec650(s, z, r); }
#define NEEDBYTE { if (n) r = 0; else LEAVE }
#define NEXTBYTE (n--, *p++)
#define NEEDBITS(j) { while (k < (j)) { NEEDBYTE b |= ((uLong)NEXTBYTE) << k; k += 8; } }
#define DUMPBITS(j) { b >>= (j); k -= (j); }
#define WRAP { if (q == s->end && s->read != s->window) { q = s->window; m = WAVAIL; } }
#define FLUSH { UPDATEOUT r = FUN_002ec650(s, z, r); LOADOUT }
#define NEEDOUT { if (m == 0) { WRAP if (m == 0) { FLUSH WRAP if (m == 0) LEAVE } } r = 0; }

int __cdecl FUN_002ea3c0(inflate_blocks_state *s, z_stream *z, int r)
{
    uInt t;
    uLong b;
    uInt k;
    Byte *p;
    uInt n;
    Byte *q;
    uInt m;

    LOAD

    while (1) switch (s->mode) {
    case 0:
        NEEDBITS(3)
        t = (uInt)b & 7;
        s->last = t & 1;
        switch (t >> 1) {
        case 0:
            DUMPBITS(3)
            t = k & 7;
            DUMPBITS(t)
            s->mode = 1;
            break;
        case 1: {
            uInt bl, bd;
            inflate_huft *tl, *td;
            FUN_002ec620(&bl, &bd, &tl, &td, z);
            s->sub.decode.codes = FUN_002eb780(bl, bd, tl, td, z);
            if (s->sub.decode.codes == 0) {
                r = -4;
                LEAVE
            }
        }
            DUMPBITS(3)
            s->mode = 6;
            break;
        case 2:
            DUMPBITS(3)
            s->mode = 3;
            break;
        case 3:
            DUMPBITS(3)
            s->mode = 9;
            z->msg = "invalid block type";
            r = -3;
            LEAVE
        }
        break;
    case 1:
        NEEDBITS(32)
        if ((((~b) >> 16) & 0xffff) != (b & 0xffff)) {
            s->mode = 9;
            z->msg = "invalid stored block lengths";
            r = -3;
            LEAVE
        }
        s->sub.left = (uInt)b & 0xffff;
        b = k = 0;
        s->mode = s->sub.left ? 2 : (s->last ? 7 : 0);
        break;
    case 2:
        if (n == 0)
            LEAVE
        NEEDOUT
        t = s->sub.left;
        if (t > n)
            t = n;
        if (t > m)
            t = m;
        memcpy(q, p, t);
        p += t;
        n -= t;
        q += t;
        m -= t;
        if ((s->sub.left -= t) != 0)
            break;
        s->mode = s->last ? 7 : 0;
        break;
    case 3:
        NEEDBITS(14)
        s->sub.trees.table = t = (uInt)b & 0x3fff;
        if ((t & 0x1f) > 29 || ((t >> 5) & 0x1f) > 29) {
            s->mode = 9;
            z->msg = "too many length or distance symbols";
            r = -3;
            LEAVE
        }
        t = 258 + (t & 0x1f) + ((t >> 5) & 0x1f);
        if ((s->sub.trees.blens = (uInt *)(*(z->zalloc))(z->opaque, t, sizeof(uInt))) == 0) {
            r = -4;
            LEAVE
        }
        DUMPBITS(14)
        s->sub.trees.index = 0;
        s->mode = 4;
    case 4:
        while (s->sub.trees.index < 4 + (s->sub.trees.table >> 10)) {
            NEEDBITS(3)
            s->sub.trees.blens[((unsigned int*)&DAT_00430c58)[s->sub.trees.index++]] = (uInt)b & 7;
            DUMPBITS(3)
        }
        while (s->sub.trees.index < 19)
            s->sub.trees.blens[((unsigned int*)&DAT_00430c58)[s->sub.trees.index++]] = 0;
        s->sub.trees.bb = 7;
        t = FUN_002ec3e0(s->sub.trees.blens, &s->sub.trees.bb, &s->sub.trees.tb, s->hufts, z);
        if (t != 0) {
            (*(z->zfree))(z->opaque, s->sub.trees.blens);
            r = t;
            if (r == -3)
                s->mode = 9;
            LEAVE
        }
        s->sub.trees.index = 0;
        s->mode = 5;
    case 5:
        while (t = s->sub.trees.table, s->sub.trees.index < 258 + (t & 0x1f) + ((t >> 5) & 0x1f)) {
            inflate_huft *h;
            uInt i, j, c;

            t = s->sub.trees.bb;
            NEEDBITS(t)
            h = s->sub.trees.tb + ((uInt)b & ((unsigned int*)&DAT_004d2838)[t]);
            t = h->bits;
            c = h->base;
            if (c < 16) {
                DUMPBITS(t)
                s->sub.trees.blens[s->sub.trees.index++] = c;
            } else {
                i = c == 18 ? 7 : c - 14;
                j = c == 18 ? 11 : 3;
                NEEDBITS(t + i)
                DUMPBITS(t)
                j += (uInt)b & ((unsigned int*)&DAT_004d2838)[i];
                DUMPBITS(i)
                i = s->sub.trees.index;
                t = s->sub.trees.table;
                if (i + j > 258 + (t & 0x1f) + ((t >> 5) & 0x1f) || (c == 16 && i < 1)) {
                    (*(z->zfree))(z->opaque, s->sub.trees.blens);
                    s->mode = 9;
                    z->msg = "invalid bit length repeat";
                    r = -3;
                    LEAVE
                }
                c = c == 16 ? s->sub.trees.blens[i - 1] : 0;
                do {
                    s->sub.trees.blens[i++] = c;
                } while (--j);
                s->sub.trees.index = i;
            }
        }
        s->sub.trees.tb = 0;
        {
            uInt bl, bd;
            inflate_huft *tl, *td;
            inflate_codes_state *c;

            bl = 9;
            bd = 6;
            t = s->sub.trees.table;
            t = FUN_002ec490(257 + (t & 0x1f), 1 + ((t >> 5) & 0x1f), s->sub.trees.blens, &bl, &bd, &tl, &td, s->hufts, z);
            (*(z->zfree))(z->opaque, s->sub.trees.blens);
            if (t != 0) {
                if (t == (uInt)-3)
                    s->mode = 9;
                r = t;
                LEAVE
            }
            if ((c = FUN_002eb780(bl, bd, tl, td, z)) == 0) {
                r = -4;
                LEAVE
            }
            s->sub.decode.codes = c;
        }
        s->mode = 6;
    case 6:
        UPDATE
        if ((r = FUN_002eb7c0(s, z, r)) != 1)
            return FUN_002ec650(s, z, r);
        r = 0;
        FUN_002ebed0(s->sub.decode.codes, z);
        LOAD
        if (!s->last) {
            s->mode = 0;
            break;
        }
        s->mode = 7;
    case 7:
        FLUSH
        if (s->read != s->write)
            LEAVE
        s->mode = 8;
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
