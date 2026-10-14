// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 5/6, incomplete)
// FUN_001e46d0 @ 0x001e46d0
struct Elem {
    int a, b, c, d, e;
};

void __cdecl FUN_001e1150(Elem *first, Elem *last, Elem *dest, Elem value, int flag);

void FUN_001e46d0(Elem *begin, Elem *end)
{
    Elem *last = end;
    while (last - begin > 1) {
        last--;
        FUN_001e1150(begin, last, last, *last, 0);
    }
}
