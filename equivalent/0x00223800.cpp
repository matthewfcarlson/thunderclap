// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00223800 @ 0x00223800
struct Elem {
    int w[10];
};

void __cdecl FUN_002234d0(Elem *first, int index, int count, Elem value);

void FUN_00223800(Elem *first, Elem *last)
{
    Elem tmp = last[-1];
    last[-1] = *first;
    FUN_002234d0(first, 0, (last - 1) - first, tmp);
}
