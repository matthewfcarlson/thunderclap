// FUN_001e4210 @ 0x001e4210
// FUN_001e4210: median-of-nine pivot selection step of a sort over 20-byte elements
struct Elem20 { char data[20]; };

extern "C" void __cdecl FUN_001e28a0(void *, void *, void *);

void __cdecl FUN_001e4210(Elem20 *first, Elem20 *mid, Elem20 *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_001e28a0((Elem20 *)first, (Elem20 *)(first + step), (Elem20 *)(first + 2 * step));
        FUN_001e28a0((Elem20 *)(mid - step), (Elem20 *)mid, (Elem20 *)(mid + step));
        FUN_001e28a0((Elem20 *)(last - 2 * step), (Elem20 *)(last - step), (Elem20 *)last);
        FUN_001e28a0((Elem20 *)(first + step), (Elem20 *)mid, (Elem20 *)(last - step));
    } else {
        FUN_001e28a0((Elem20 *)first, (Elem20 *)mid, (Elem20 *)last);
    }
}
