struct Item {
    int count;
    int* value;
};
extern Item gItems[12];
extern int gZero;
int* __cdecl FUN_000b08e0(int a, int b, int c) {
    if (a >= 0 && a < 2 && b >= 0 && b < 2 && c >= 0 && c < 3) {
        Item* p = &gItems[(a * 2 + b) * 3 + c];
        if (p->count > 0)
            return p->value;
    }
    return &gZero;
}