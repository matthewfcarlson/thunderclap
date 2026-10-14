struct Item {
    int a;
    int b;
};
int* __cdecl FUN_00339a40(int dummy, Item* p, int* out) {
    int b = p->b;
    if (!b)
        return 0;
    *out = b;
    p->b = 0;
    return (int*)p->a;
}
