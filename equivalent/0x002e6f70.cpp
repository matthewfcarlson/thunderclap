// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 62/64, incomplete)
// FUN_002e6f70 @ 0x002e6f70
// zlib 1.1.x inflate()
struct inflate_blocks_state;

struct inflate_state {
    int mode;
    union {
        unsigned int method;
        struct {
            unsigned long was;
            unsigned long need;
        } check;
        unsigned int marker;
    } sub;
    int nowrap;
    unsigned int wbits;
    inflate_blocks_state *blocks;
};

struct z_stream_2e6f70 {
    unsigned char *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char *msg;
    inflate_state *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
};

enum {
    METHOD = 0, FLAG, DICT4, DICT3, DICT2, DICT1, DICT0, BLOCKS,
    CHECK4, CHECK3, CHECK2, CHECK1, DONE, BAD
};

int FUN_002ea3c0(inflate_blocks_state *s, z_stream_2e6f70 *z, int r);
void FUN_002ea2a0(inflate_blocks_state *s, z_stream_2e6f70 *z, unsigned long *c);

#define NEEDBYTE { if (z->avail_in == 0) return r; r = f; }
#define NEXTBYTE (z->avail_in--, z->total_in++, *z->next_in++)

int FUN_002e6f70(z_stream_2e6f70 *z, int f)
{
    int r;
    unsigned int b;

    if (z == 0 || z->state == 0 || z->next_in == 0) {
        return -2;
    }
    f = (f == 4) ? -5 : 0;
    r = -5;
    for (;;) {
        switch (z->state->mode) {
        case METHOD:
            NEEDBYTE
            if (((z->state->sub.method = NEXTBYTE) & 0xf) != 8) {
                z->state->mode = BAD;
                z->msg = (char *)"unknown compression method";
                z->state->sub.marker = 5;
                break;
            }
            if ((z->state->sub.method >> 4) + 8 > z->state->wbits) {
                z->state->mode = BAD;
                z->msg = (char *)"invalid window size";
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = FLAG;
        case FLAG:
            NEEDBYTE
            b = NEXTBYTE;
            if (((z->state->sub.method << 8) + b) % 31) {
                z->state->mode = BAD;
                z->msg = (char *)"incorrect header check";
                z->state->sub.marker = 5;
                break;
            }
            if (!(b & 0x20)) {
                z->state->mode = BLOCKS;
                break;
            }
            z->state->mode = DICT4;
        case DICT4:
            NEEDBYTE
            z->state->sub.check.need = (unsigned long)NEXTBYTE << 24;
            z->state->mode = DICT3;
        case DICT3:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 16;
            z->state->mode = DICT2;
        case DICT2:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 8;
            z->state->mode = DICT1;
        case DICT1:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE;
            z->adler = z->state->sub.check.need;
            z->state->mode = DICT0;
            return 2;
        case DICT0:
            z->state->mode = BAD;
            z->msg = (char *)"need dictionary";
            z->state->sub.marker = 0;
            return -2;
        case BLOCKS:
            r = FUN_002ea3c0(z->state->blocks, z, r);
            if (r == -3) {
                z->state->mode = BAD;
                z->state->sub.marker = 0;
                break;
            }
            if (r == 0) {
                r = f;
            }
            if (r != 1) {
                return r;
            }
            r = f;
            FUN_002ea2a0(z->state->blocks, z, &z->state->sub.check.was);
            if (z->state->nowrap) {
                z->state->mode = DONE;
                break;
            }
            z->state->mode = CHECK4;
        case CHECK4:
            NEEDBYTE
            z->state->sub.check.need = (unsigned long)NEXTBYTE << 24;
            z->state->mode = CHECK3;
        case CHECK3:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 16;
            z->state->mode = CHECK2;
        case CHECK2:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE << 8;
            z->state->mode = CHECK1;
        case CHECK1:
            NEEDBYTE
            z->state->sub.check.need += (unsigned long)NEXTBYTE;
            if (z->state->sub.check.was != z->state->sub.check.need) {
                z->state->mode = BAD;
                z->msg = (char *)"incorrect data check";
                z->state->sub.marker = 5;
                break;
            }
            z->state->mode = DONE;
        case DONE:
            return 1;
        case BAD:
            return -3;
        default:
            return -2;
        }
    }
}
