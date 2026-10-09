extern int g_table[];
struct Obj {
    char pad[4];
    int index;
};
int __cdecl compare(Obj* a, Obj* b) {
    if (a != 0 && b != 0 && g_table[a->index] > g_table[b->index])
        return -1;
    return 1;
}