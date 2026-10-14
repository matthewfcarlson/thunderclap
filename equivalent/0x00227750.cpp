// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00227750 @ 0x00227750
// FUN_00227750: median-of-nine pivot selection step of a sort over 12-byte elements
struct Elem12 { char data[12]; };

void __cdecl FUN_00227300(Elem12 *a, Elem12 *b, Elem12 *c);

void __cdecl FUN_00227750(Elem12 *first, Elem12 *mid, Elem12 *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_00227300(first, first + step, first + 2 * step);
        FUN_00227300(mid - step, mid, mid + step);
        FUN_00227300(last - 2 * step, last - step, last);
        FUN_00227300(first + step, mid, last - step);
    } else {
        FUN_00227300(first, mid, last);
    }
}
