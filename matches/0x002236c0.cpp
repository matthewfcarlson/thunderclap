// FUN_002236c0 @ 0x002236c0
// FUN_002236c0: median-of-nine pivot selection step of a sort over 40-byte elements
struct Elem40 { char data[40]; };

void __cdecl FUN_002233e0(Elem40 *a, Elem40 *b, Elem40 *c);

void __cdecl FUN_002236c0(Elem40 *first, Elem40 *mid, Elem40 *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_002233e0(first, first + step, first + 2 * step);
        FUN_002233e0(mid - step, mid, mid + step);
        FUN_002233e0(last - 2 * step, last - step, last);
        FUN_002233e0(first + step, mid, last - step);
    } else {
        FUN_002233e0(first, mid, last);
    }
}
