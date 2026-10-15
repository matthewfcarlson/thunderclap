struct Item {
    int a, b, c, d, e;
};
Item* __cdecl FUN_0030dbd0(Item* first, Item* last, Item* dest) {
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return dest;
}