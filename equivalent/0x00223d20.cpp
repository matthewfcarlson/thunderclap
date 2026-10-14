// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 4/4)
// FUN_00223d20 @ 0x00223d20
struct Elem {
    int w[10];
};

void __cdecl FUN_002234d0(Elem *first, int index, int count, Elem value);

void FUN_00223d20(Elem *first, Elem *last)
{
    while (last - first > 1) {
        --last;
        Elem tmp = *last;
        *last = *first;
        FUN_002234d0(first, 0, last - first, tmp);
    }
}
