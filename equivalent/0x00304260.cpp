// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 4/4)
// FUN_00304260 @ 0x00304260
// FUN_00304260: heap sort tail (repeatedly move the first element to the end and sift down)
struct Elem_304260 {
    char data[0x44];
    void FUN_002f7a90(Elem_304260 *src);
};

void __cdecl FUN_003032d0(Elem_304260 *first, int hole, int len, Elem_304260 value);

extern "C" void __cdecl FUN_00304260(void *first, void * last_)
{
    Elem_304260 * last = (Elem_304260 *)last_;
    while (last - ((Elem_304260 *)first) > 1) {
        Elem_304260 value = *(last - 1);
        (last - 1)->FUN_002f7a90(((Elem_304260 *)first));
        FUN_003032d0(((Elem_304260 *)first), 0, (int)((last - 1) - ((Elem_304260 *)first)), value);
        last--;
    }
}
