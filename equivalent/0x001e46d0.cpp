// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 5/6, incomplete)
// FUN_001e46d0 @ 0x001e46d0
struct Elem_1e46d0 {
    int a, b, c, d, e;
};

void __cdecl FUN_001e1150(Elem_1e46d0 *first, Elem_1e46d0 *last, Elem_1e46d0 *dest, Elem_1e46d0 value, int flag);

void FUN_001e46d0(Elem_1e46d0 *begin, Elem_1e46d0 *end)
{
    Elem_1e46d0 *last = end;
    while (last - begin > 1) {
        last--;
        FUN_001e1150(begin, last, last, *last, 0);
    }
}
