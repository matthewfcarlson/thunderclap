// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 5/6, incomplete)
// FUN_001e46d0 @ 0x001e46d0
struct Elem_1e46d0 {
    int a, b, c, d, e;
};

void __cdecl FUN_001e1150(Elem_1e46d0 *first, Elem_1e46d0 *last, Elem_1e46d0 *dest, Elem_1e46d0 value, int flag);

extern "C" void FUN_001e46d0(void *begin, void *end)
{
    Elem_1e46d0 *last = ((Elem_1e46d0 *)end);
    while (last - ((Elem_1e46d0 *)begin) > 1) {
        last--;
        FUN_001e1150(((Elem_1e46d0 *)begin), last, last, *last, 0);
    }
}
