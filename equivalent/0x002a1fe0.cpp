// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002a1fe0 @ 0x002a1fe0
// median-of-nine pivot selection step of a sort over 4-byte elements with a comparator
typedef int Elem4;

void __cdecl FUN_002a1e00(Elem4 *a, Elem4 *b, Elem4 *c, void *cmp);

void __cdecl FUN_002a1fe0(Elem4 *first, Elem4 *mid, Elem4 *last, void *cmp)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_002a1e00(first, first + step, first + 2 * step, cmp);
        FUN_002a1e00(mid - step, mid, mid + step, cmp);
        FUN_002a1e00(last - 2 * step, last - step, last, cmp);
        FUN_002a1e00(first + step, mid, last - step, cmp);
    } else {
        FUN_002a1e00(first, mid, last, cmp);
    }
}
