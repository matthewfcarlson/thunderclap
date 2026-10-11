// STATUS: equivalent (tools/equiv.py level 3: 10 inputs, branch coverage 37/42, incomplete)
// FUN_002a2200 @ 0x002a2200
typedef bool (*Less)(int a, int b);

struct Range {
    int *first;
    int *second;
};

void FUN_002a1fe0(int *first, int *mid, int *last, Less less);

static void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Partitions [first, last) around a median-of-three pivot into
// [first, lo) < pivot, [lo, hi) == pivot, [hi, last) > pivot and returns {lo, hi}.
Range *FUN_002a2200(Range *out, int *first, int *last, Less less)
{
    int *mid = first + (last - first) / 2;
    FUN_002a1fe0(first, mid, last - 1, less);
    int *pivotLo = mid;
    int *pivotHi = pivotLo + 1;

    while (first < pivotLo && !less(pivotLo[-1], *pivotLo) && !less(*pivotLo, pivotLo[-1]))
        --pivotLo;
    while (pivotHi < last && !less(*pivotHi, *pivotLo) && !less(*pivotLo, *pivotHi))
        ++pivotHi;

    int *up = pivotHi;
    int *down = pivotLo;
    for (;;) {
        for (; up < last; ++up) {
            if (less(*pivotLo, *up)) {
            } else if (less(*up, *pivotLo)) {
                break;
            } else {
                if (pivotHi++ != up)
                    Swap(pivotHi - 1, up);
            }
        }
        for (; first < down; --down) {
            if (less(down[-1], *pivotLo)) {
            } else if (less(*pivotLo, down[-1])) {
                break;
            } else {
                if (--pivotLo != down - 1)
                    Swap(pivotLo, down - 1);
            }
        }
        if (down == first && up == last) {
            out->first = pivotLo;
            out->second = pivotHi;
            return out;
        }
        if (down == first) {
            if (pivotHi != up)
                Swap(pivotLo, pivotHi);
            ++pivotHi;
            Swap(pivotLo, up);
            ++pivotLo;
            ++up;
        } else if (up == last) {
            --down;
            --pivotLo;
            if (down != pivotLo)
                Swap(down, pivotLo);
            --pivotHi;
            Swap(pivotLo, pivotHi);
        } else {
            --down;
            Swap(up, down);
            ++up;
        }
    }
}
