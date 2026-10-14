// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00229ea0 @ 0x00229ea0
struct Elem_229ea0 { int x, y, z; };
void __cdecl FUN_00229630(Elem_229ea0 *first, int hole, int len, Elem_229ea0 value);

// Heap-sort phase: repeatedly moves the root to the back and re-sifts.
void __cdecl FUN_00229ea0(Elem_229ea0 *first, Elem_229ea0 *last)
{
    while (last - first > 1) {
        --last;
        Elem_229ea0 value = *last;
        *last = *first;
        FUN_00229630(first, 0, last - first, value);
    }
}
