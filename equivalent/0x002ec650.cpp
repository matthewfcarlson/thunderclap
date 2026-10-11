// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 22/22)
// FUN_002ec650 @ 0x002ec650
extern "C" void *memcpy(void *dst, const void *src, unsigned n);

struct z_stream {
    unsigned char *next_in;
    unsigned avail_in;
    unsigned total_in;
    unsigned char *next_out;
    unsigned avail_out;
    unsigned total_out;
    char pad[0x30 - 0x18];
    unsigned adler;
};

typedef unsigned (*check_fn)(unsigned, const unsigned char *, unsigned);

struct inflate_blocks_state {
    char pad[0x28];
    unsigned char *window;
    unsigned char *end;
    unsigned char *read;
    unsigned char *write;
    check_fn checkfn;
    unsigned check;
};

int FUN_002ec650(inflate_blocks_state *s, z_stream *z, int r)
{
    unsigned char *p = z->next_out;
    unsigned char *q = s->read;
    unsigned n;

    n = (unsigned)((q <= s->write ? s->write : s->end) - q);
    if (n > z->avail_out)
        n = z->avail_out;
    if (n != 0 && r == -5)
        r = 0;
    z->avail_out -= n;
    z->total_out += n;
    if (s->checkfn != 0)
        z->adler = s->check = s->checkfn(s->check, q, n);
    memcpy(p, q, n);
    p += n;
    q += n;

    if (q == s->end) {
        q = s->window;
        if (s->write == s->end)
            s->write = s->window;
        n = (unsigned)(s->write - q);
        if (n > z->avail_out)
            n = z->avail_out;
        if (n != 0 && r == -5)
            r = 0;
        z->avail_out -= n;
        z->total_out += n;
        if (s->checkfn != 0)
            z->adler = s->check = s->checkfn(s->check, q, n);
        memcpy(p, q, n);
        p += n;
        q += n;
    }

    z->next_out = p;
    s->read = q;
    return r;
}
