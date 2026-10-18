// FUN_00229840 @ 0x00229840
// FUN_00229840: median-of-nine pivot selection step of a sort over 12-byte elements
struct Elem12_229840 { char data[12]; };

void __cdecl FUN_00229560(Elem12_229840 *a, Elem12_229840 *b, Elem12_229840 *c);

void __cdecl FUN_00229840(Elem12_229840 *first, Elem12_229840 *mid, Elem12_229840 *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_00229560(first, first + step, first + 2 * step);
        FUN_00229560(mid - step, mid, mid + step);
        FUN_00229560(last - 2 * step, last - step, last);
        FUN_00229560(first + step, mid, last - step);
    } else {
        FUN_00229560(first, mid, last);
    }
}
