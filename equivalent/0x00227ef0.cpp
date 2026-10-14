// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00227ef0 @ 0x00227ef0
struct Elem { int x, y, z; };
void __cdecl FUN_002273d0(Elem *first, int hole, int len, Elem value);

// Heap-sort phase: repeatedly moves the root to the back and re-sifts.
void __cdecl FUN_00227ef0(Elem *first, Elem *last)
{
    while (last - first > 1) {
        --last;
        Elem value = *last;
        *last = *first;
        FUN_002273d0(first, 0, last - first, value);
    }
}
