// FUN_001e4210 @ 0x001e4210
// FUN_001e4210: median-of-nine pivot selection step of a sort over 20-byte elements
struct Elem20 { char data[20]; };

void __cdecl FUN_001e28a0(Elem20 *a, Elem20 *b, Elem20 *c);

void __cdecl FUN_001e4210(Elem20 *first, Elem20 *mid, Elem20 *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_001e28a0(first, first + step, first + 2 * step);
        FUN_001e28a0(mid - step, mid, mid + step);
        FUN_001e28a0(last - 2 * step, last - step, last);
        FUN_001e28a0(first + step, mid, last - step);
    } else {
        FUN_001e28a0(first, mid, last);
    }
}
