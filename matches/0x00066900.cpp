struct Item {
    float x;
};
struct Other {
    char pad[16];
    float x;
};
int __cdecl FUN_00066900(const Item* a, const Other* b) {
    if (a->x < b->x)
        return -1;
    if (b->x < a->x)
        return 1;
    return 0;
}