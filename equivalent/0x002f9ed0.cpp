// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 21/24, incomplete)
// FUN_002f9ed0 @ 0x002f9ed0
// Compacts the pool's strings (16-byte records holding [begin, end) ranges of 16-bit characters)
// to the front of the pool's character buffer and resizes the buffer to the used length.
// Returns the used length.
void *__cdecl FUN_0008d6d0(unsigned int bytes);

struct Str_2f9ed0 {
    int pad0;
    int pad4;
    unsigned short *begin;          // 8
    unsigned short *end;            // 0xc
};

struct Buffer_2f9ed0 {
    unsigned short *begin;          // 0
    unsigned short *end;            // 4
    unsigned short *cap;            // 8
    void FUN_002f9bc0(unsigned short *pos, unsigned int count, const unsigned short *value);
};

struct Pool_2f9ed0 {
    char pad00[0x30];
    Str_2f9ed0 *strBegin;                  // 0x30
    Str_2f9ed0 *strEnd;                    // 0x34
    char pad38[8];
    Buffer_2f9ed0 buf;                     // 0x40

    unsigned int FUN_002f9ed0();
};

unsigned int Pool_2f9ed0::FUN_002f9ed0()
{
    unsigned short *dest = buf.begin;
    for (Str_2f9ed0 *s = strBegin; s != strEnd; s++) {
        unsigned short *src = s->begin;
        if (src != dest) {
            unsigned short *last = s->end;
            unsigned short *d = dest;
            while (src != last) {
                *d = *src;
                src++;
                d++;
            }
            s->begin = dest;
            s->end = d;
        }
        dest = s->end;
    }

    unsigned int n = dest - buf.begin;
    unsigned short fill = 0;
    if (buf.begin == 0) {
        if (n == 0) {
            buf.begin = 0;
            buf.end = 0;
            buf.cap = 0;
        } else {
            unsigned int bytes = n * 2;
            unsigned short *p = (unsigned short *)FUN_0008d6d0(bytes);
            buf.begin = p;
            if (p) {
                buf.end = p;
                buf.cap = p + n;
            } else {
                buf.end = 0;
                buf.cap = 0;
            }
        }
    }
    unsigned int size = buf.end - buf.begin;
    if (n > size) {
        buf.FUN_002f9bc0(buf.end, n - size, &fill);
        return n;
    }
    if (n < size)
        buf.end = buf.begin + n;
    return n;
}
