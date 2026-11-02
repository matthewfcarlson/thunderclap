// FUN_00227750 @ 0x00227750
// FUN_00227750: median-of-nine pivot selection step of a sort over 12-byte elements
struct Elem12_227750 { char data[12]; };

extern "C" void __cdecl FUN_00227300(void *, void *, void *);

extern "C" void __cdecl FUN_00227750(void *first, void *mid, void *last)
{
    int n = (int)(((Elem12_227750 *)last) - ((Elem12_227750 *)first));
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_00227300((Elem12_227750 *)((Elem12_227750 *)first), (Elem12_227750 *)(((Elem12_227750 *)first) + step), (Elem12_227750 *)(((Elem12_227750 *)first) + 2 * step));
        FUN_00227300((Elem12_227750 *)(((Elem12_227750 *)mid) - step), (Elem12_227750 *)((Elem12_227750 *)mid), (Elem12_227750 *)(((Elem12_227750 *)mid) + step));
        FUN_00227300((Elem12_227750 *)(((Elem12_227750 *)last) - 2 * step), (Elem12_227750 *)(((Elem12_227750 *)last) - step), (Elem12_227750 *)((Elem12_227750 *)last));
        FUN_00227300((Elem12_227750 *)(((Elem12_227750 *)first) + step), (Elem12_227750 *)((Elem12_227750 *)mid), (Elem12_227750 *)(((Elem12_227750 *)last) - step));
    } else {
        FUN_00227300((Elem12_227750 *)((Elem12_227750 *)first), (Elem12_227750 *)((Elem12_227750 *)mid), (Elem12_227750 *)((Elem12_227750 *)last));
    }
}
