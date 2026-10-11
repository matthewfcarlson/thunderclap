// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 33/36, incomplete)
// FUN_00307060 @ 0x00307060
extern unsigned short* DAT_0055543c;
extern unsigned short* DAT_00555440;

// A packed stream of 16-bit words: each record has a header (selector in bits 12-13,
// type in bits 14-15), literal words that are appended to a global 0x400-entry buffer,
// and offsets to follow into nested records.
class Stream {
public:
    void FUN_00307060(const unsigned short* limits, int unused);
};

void Stream::FUN_00307060(const unsigned short* limits, int unused)
{
    const unsigned short* p = (const unsigned short*)this;
    for (;;) {
        unsigned hdr = p[0];
        unsigned sel = (hdr >> 12) & 3;
        unsigned short count;
        unsigned short skipA = 0;
        unsigned short skipB = 0;
        switch (sel) {
        case 0:
            count = hdr & 0xfff;
            break;
        case 1:
            skipA = (hdr >> 6) & 0x3f;
            count = hdr & 0x3f;
            break;
        case 2:
            skipB = (hdr >> 6) & 0x3f;
            count = hdr & 0x3f;
            break;
        default:
            skipA = (hdr >> 8) & 0xf;
            skipB = (hdr >> 4) & 0xf;
            count = hdr & 0xf;
            break;
        }

        const unsigned short* s = p + 1;
        for (unsigned short n = count; n != 0; n--) {
            unsigned short idx = *DAT_0055543c;
            if (idx < 0x400) {
                DAT_00555440[idx] = *s;
                (*DAT_0055543c)++;
            }
            s++;
        }

        unsigned short type = p[0] >> 14;
        if (type == 3)
            return;
        unsigned short key = *s;
        s++;

        if (limits[type] > key) {
            if (sel & 1)
                s += skipA;
            else
                s++;
        } else if ((sel & 1) == 0) {
            const unsigned short* child = p + *s;
            s++;
            ((Stream*)child)->FUN_00307060(limits, unused);
        } else {
            for (unsigned short n = skipA; n != 0; n--) {
                unsigned short idx = *DAT_0055543c;
                if (idx < 0x400) {
                    DAT_00555440[idx] = *s;
                    (*DAT_0055543c)++;
                }
                s++;
            }
        }

        if (limits[type + 3] < key)
            return;
        if ((sel & 2) == 0) {
            p = p + *s;
            continue;
        }
        for (unsigned short n = skipB; n != 0; n--) {
            unsigned short idx = *DAT_0055543c;
            if (idx < 0x400) {
                DAT_00555440[idx] = *s;
                (*DAT_0055543c)++;
            }
            s++;
        }
        return;
    }
}
