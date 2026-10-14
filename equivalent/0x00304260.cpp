// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 4/4)
// FUN_00304260 @ 0x00304260
// FUN_00304260: heap sort tail (repeatedly move the first element to the end and sift down)
struct Elem {
    char data[0x44];
    void FUN_002f7a90(Elem *src);
};

void __cdecl FUN_003032d0(Elem *first, int hole, int len, Elem value);

void __cdecl FUN_00304260(Elem *first, Elem *last)
{
    while (last - first > 1) {
        Elem value = *(last - 1);
        (last - 1)->FUN_002f7a90(first);
        FUN_003032d0(first, 0, (int)((last - 1) - first), value);
        last--;
    }
}
