// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 50/50)
// FUN_002d9170 @ 0x002d9170
struct Source_2d9170 {
    char pad0[0x68];
    unsigned int flags;
    char pad6c[0x112 - 0x6c];
    unsigned short count;
    char pad114[0x130 - 0x114];
    unsigned char tag[10];
    char pad13a[0x154 - 0x13a];
    unsigned int value154;
    char pad158[0x1e4 - 0x158];
    void *link;
};

struct Format_2d9170 {
    unsigned int width;
    char pad4[0xc - 4];
    unsigned int rowBytes;
    char pad10[0x16 - 0x10];
    unsigned short w16;
    unsigned char depth;
    unsigned char mode;
    char pad1a[0x1d - 0x1a];
    unsigned char channels;
    unsigned char bits;
    char pad1f[0x28 - 0x1f];
    unsigned int value28;
    char pad2c[0x5a - 0x2c];
    unsigned char tag[10];
};

void FUN_002d9170(Source_2d9170 *src, Format_2d9170 *fmt)
{
    unsigned char bl = 8;

    if (src->flags & 0x1000) {
        if (fmt->mode == 3) {
            fmt->mode = (src->count != 0) * 4 + 2;
            fmt->depth = bl;
        } else {
            if (src->count != 0)
                fmt->mode = fmt->mode | 4;
            if (fmt->depth < bl)
                fmt->depth = bl;
        }
        fmt->w16 = 0;
    }
    if (src->flags & 0x80) {
        fmt->mode &= 0xfb;
        fmt->w16 = 0;
        for (int i = 0; i < 10; i++)
            fmt->tag[i] = src->tag[i];
    }
    if (src->flags & 0x2000)
        fmt->value28 = src->value154;
    if (src->flags & 0x400) {
        if (fmt->depth == 0x10)
            fmt->depth = bl;
    }
    if (src->flags & 0x40) {
        unsigned char m = fmt->mode;
        if ((m == 2 || m == 6) && src->link != 0 && fmt->depth == bl)
            fmt->mode = 3;
    }
    if (src->flags & 4) {
        if (fmt->depth < bl)
            fmt->depth = bl;
    }
    if (src->flags & 0x4000)
        fmt->mode |= 2;
    if (src->flags & 0x600000)
        fmt->mode &= 0xfd;
    unsigned char m = fmt->mode;
    if (m != 3 && (m & 2))
        fmt->channels = 3;
    else
        fmt->channels = 1;
    if (src->flags & 0x40000) {
        m &= 0xfb;
        fmt->mode = m;
    }
    m = fmt->mode;
    if (m & 4)
        fmt->channels++;
    if (src->flags & 0x8000) {
        if (m == 2 || m == 0)
            fmt->channels++;
    }
    unsigned char bits = (unsigned char)(fmt->depth * fmt->channels);
    fmt->bits = bits;
    fmt->rowBytes = (bits * fmt->width + 7) >> 3;
}
