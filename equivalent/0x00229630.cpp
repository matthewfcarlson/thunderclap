// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 8/8)
// FUN_00229630 @ 0x00229630
struct Item {
    int a;
    float key;
    int c;
};

void __cdecl FUN_00228910(Item *first, int hole, int top, Item value);

// Sift-down half of an adjust-heap (children compared by key) followed by FUN_00228910 sift-up.
void __cdecl FUN_00229630(Item *first, int top, int bottom, Item value)
{
    int hole = top;
    int idx = 2 * top + 2;
    while (idx < bottom) {
        if (first[idx].key > first[idx - 1].key)
            idx--;
        first[hole] = first[idx];
        hole = idx;
        idx = 2 * idx + 2;
    }
    if (idx == bottom) {
        first[hole] = first[bottom - 1];
        hole = bottom - 1;
    }
    FUN_00228910(first, hole, top, value);
}
