// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 32/32)
// FUN_002f41e0 @ 0x002f41e0
static __forceinline void SwapIfLess(unsigned short *a, unsigned short *b)
{
    if (*a < *b) {
        unsigned short t = *a;
        *a = *b;
        *b = t;
    }
}

static __forceinline void Med3(unsigned short *first, unsigned short *mid, unsigned short *last)
{
    SwapIfLess(mid, first);
    SwapIfLess(last, mid);
    SwapIfLess(mid, first);
}

void __cdecl FUN_002f41e0(unsigned short *first, unsigned short *mid, unsigned short *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        Med3(first, first + step, first + 2 * step);
        Med3(mid - step, mid, mid + step);
        Med3(last - 2 * step, last - step, last);
        Med3(first + step, mid, last - step);
    } else {
        Med3(first, mid, last);
    }
}
