// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 36/42, incomplete)
// FUN_00300100 @ 0x00300100
struct UIntRange_300100 {
    unsigned int *first;
    unsigned int *second;
};

void __cdecl FUN_002ffce0(unsigned int *a, unsigned int *b, unsigned int *c);

// std::_Unguarded_partition for unsigned int* (three-way split around a median pivot).
UIntRange_300100 *__cdecl FUN_00300100(UIntRange_300100 *out, unsigned int *first, unsigned int *last)
{
    unsigned int *mid = first + (last - first) / 2;
    FUN_002ffce0(first, mid, last - 1);

    unsigned int *pfirst = mid;
    unsigned int *plast = pfirst + 1;
    while (first < pfirst && !(*(pfirst - 1) < *pfirst) && !(*pfirst < *(pfirst - 1)))
        --pfirst;
    while (plast < last && !(*plast < *pfirst) && !(*pfirst < *plast))
        ++plast;

    unsigned int *gfirst = plast;
    unsigned int *glast = pfirst;
    unsigned int t;

    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (*pfirst < *gfirst)
                ;
            else if (*gfirst < *pfirst)
                break;
            else {
                t = *plast;
                *plast = *gfirst;
                *gfirst = t;
                ++plast;
            }
        }
        for (; first < glast; --glast) {
            if (*(glast - 1) < *pfirst)
                ;
            else if (*pfirst < *(glast - 1))
                break;
            else {
                --pfirst;
                t = *pfirst;
                *pfirst = *(glast - 1);
                *(glast - 1) = t;
            }
        }
        if (glast == first && gfirst == last) {
            out->first = pfirst;
            out->second = plast;
            return out;
        }
        if (glast == first) {
            if (plast != gfirst) {
                t = *pfirst;
                *pfirst = *plast;
                *plast = t;
            }
            ++plast;
            t = *pfirst;
            *pfirst = *gfirst;
            *gfirst = t;
            ++pfirst;
            ++gfirst;
        } else if (gfirst == last) {
            --glast;
            --pfirst;
            if (glast != pfirst) {
                t = *glast;
                *glast = *pfirst;
                *pfirst = t;
            }
            --plast;
            t = *pfirst;
            *pfirst = *plast;
            *plast = t;
        } else {
            --glast;
            t = *gfirst;
            *gfirst = *glast;
            *glast = t;
            ++gfirst;
        }
    }
}
