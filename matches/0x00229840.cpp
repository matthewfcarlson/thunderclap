// FUN_00229840 @ 0x00229840
// FUN_00229840: median-of-nine pivot selection step of a sort over 12-byte elements
struct Elem12_229840 { char data[12]; };

extern "C" void __cdecl FUN_00229560(void *, void *, void *);

extern "C" void __cdecl FUN_00229840(void *first, void *mid, void *last)
{
    int n = (int)(((Elem12_229840 *)last) - ((Elem12_229840 *)first));
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_00229560((Elem12_229840 *)((Elem12_229840 *)first), (Elem12_229840 *)(((Elem12_229840 *)first) + step), (Elem12_229840 *)(((Elem12_229840 *)first) + 2 * step));
        FUN_00229560((Elem12_229840 *)(((Elem12_229840 *)mid) - step), (Elem12_229840 *)((Elem12_229840 *)mid), (Elem12_229840 *)(((Elem12_229840 *)mid) + step));
        FUN_00229560((Elem12_229840 *)(((Elem12_229840 *)last) - 2 * step), (Elem12_229840 *)(((Elem12_229840 *)last) - step), (Elem12_229840 *)((Elem12_229840 *)last));
        FUN_00229560((Elem12_229840 *)(((Elem12_229840 *)first) + step), (Elem12_229840 *)((Elem12_229840 *)mid), (Elem12_229840 *)(((Elem12_229840 *)last) - step));
    } else {
        FUN_00229560((Elem12_229840 *)((Elem12_229840 *)first), (Elem12_229840 *)((Elem12_229840 *)mid), (Elem12_229840 *)((Elem12_229840 *)last));
    }
}
