// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 4/4)
// FUN_00223760 @ 0x00223760
struct Elem {
    int w[10];
};

void __cdecl FUN_002234d0(Elem *first, int index, int count, Elem value);

void FUN_00223760(Elem *first, Elem *last)
{
    int n = last - first;
    int i = n / 2;
    last = first + i;
    while (i > 0) {
        --last;
        --i;
        FUN_002234d0(first, i, n, *last);
    }
}
