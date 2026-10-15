// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 17/19, incomplete)
// fight::BinReader::vfunc_5 @ 0x0023c040
// fight::BinReader::vfunc_5 @ 0x0023c040: read a 12-byte record (three words), byte-swapping if needed
struct Stream {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned int read(void *buf, unsigned int n);
};

namespace fight {

struct BinReader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2, unsigned char *buf);
    char pad04[4];
    Stream *stream;
    char padc;
    char swapBytes;
    char pade[2];
    int length;
    char pad14[0xc];
    unsigned int remaining;
};

static void reverse4(unsigned char *p)
{
    unsigned char *lo = p;
    unsigned char *hi = p + 3;
    while (lo < hi) {
        unsigned char t = *hi;
        *hi = *lo;
        *lo = t;
        lo++;
        hi--;
    }
}

bool BinReader::vfunc_5(int a1, int a2, unsigned char *buf)
{
    length = -1;
    unsigned int want = remaining;
    if (want > 12)
        want = 12;
    unsigned int got = stream->read(buf, want);
    remaining -= want;
    bool ok = got == 12;
    if (swapBytes) {
        reverse4(buf);
        if (swapBytes) {
            reverse4(buf + 4);
            if (swapBytes)
                reverse4(buf + 8);
        }
    }
    return ok;
}

}
