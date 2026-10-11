// STATUS: equivalent (tools/equiv.py level 3: 28 inputs, branch coverage 37/42, incomplete)
// FUN_002f43f0 @ 0x002f43f0
struct UShortRange {
    unsigned short* first;
    unsigned short* last;
};

void FUN_002f41e0(unsigned short* a, unsigned short* b, unsigned short* c);

static void SwapU16(unsigned short* a, unsigned short* b)
{
    unsigned short t = *a;
    *a = *b;
    *b = t;
}

// std::_Partition for unsigned short, with equal-range grouping; returns the
// range of elements equal to the median-of-three pivot.
UShortRange* FUN_002f43f0(UShortRange* out, unsigned short* first, unsigned short* last)
{
    int n = (int)(last - first);
    unsigned short* mid = first + n / 2;
    FUN_002f41e0(first, mid, last - 1);

    unsigned short* pmid = mid;
    while (first < pmid && !(pmid[-1] < *pmid) && !(*pmid < pmid[-1]))
        --pmid;
    unsigned short* pfirst = mid + 1;
    while (pfirst < last && !(*pmid < *pfirst) && !(*pfirst < *pmid))
        ++pfirst;

    unsigned short* gfirst = pfirst;
    unsigned short* glast = pmid;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (*pmid < *gfirst) {
            } else if (*gfirst < *pmid) {
                break;
            } else {
                SwapU16(pfirst, gfirst);
                ++pfirst;
            }
        }
        for (; first < glast; --glast) {
            if (glast[-1] < *pmid) {
            } else if (*pmid < glast[-1]) {
                break;
            } else {
                --pmid;
                SwapU16(pmid, glast - 1);
            }
        }
        if (glast == first) {
            if (gfirst == last) {
                out->last = pfirst;
                out->first = pmid;
                return out;
            }
            if (pfirst != gfirst)
                SwapU16(pfirst, pmid);
            SwapU16(pmid, gfirst);
            ++pfirst;
            ++pmid;
            ++gfirst;
        } else {
            --glast;
            if (gfirst == last) {
                --pmid;
                if (glast != pmid)
                    SwapU16(glast, pmid);
                --pfirst;
                SwapU16(pmid, pfirst);
            } else {
                SwapU16(gfirst, glast);
                ++gfirst;
            }
        }
    }
}
