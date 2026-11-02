// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00304370 @ 0x00304370
struct Item_304370 { char data[68]; };
struct Partition { Item_304370* first; Item_304370* second; };
void __cdecl FUN_003037f0(Partition*, Item_304370*, Item_304370*);
extern "C" void __cdecl FUN_00303680(void *, void *);
void __cdecl FUN_00303480(Item_304370*, Item_304370*, int, int);
extern "C" void __cdecl FUN_00304260(void *, void *);
extern "C" void __cdecl FUN_00304370(void * first_, void * last_, int depth) {
    Item_304370 * first = (Item_304370 *)first_;
    Item_304370 * last = (Item_304370 *)last_;
    while (last - first > 32) {
        if (depth <= 0) {
            if (last - first > 1) FUN_00303480(first, last, 0, 0);
            FUN_00304260((Item_304370 *)first, (Item_304370 *)last);
            return;
        }
        Partition middle;
        FUN_003037f0(&middle, first, last);
        Item_304370* upper = middle.second;
        depth = depth / 2 + (depth / 2) / 2;
        if (middle.first - first < last - upper) {
            FUN_00304370((Item_304370 *)first, (Item_304370 *)(middle.first), depth);
            first = upper;
        } else {
            FUN_00304370((Item_304370 *)upper, (Item_304370 *)last, depth);
            last = middle.first;
        }
    }
    if (last - first > 1) FUN_00303680((Item_304370 *)first, (Item_304370 *)last);
}
