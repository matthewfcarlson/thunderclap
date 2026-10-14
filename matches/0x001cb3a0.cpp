extern int g_table_1cb3a0[];
struct Obj_1cb3a0 {
    char pad[4];
    int index;
};
int __cdecl compare(Obj_1cb3a0* a, Obj_1cb3a0* b) {
    if (a != 0 && b != 0 && g_table_1cb3a0[a->index] > g_table_1cb3a0[b->index])
        return -1;
    return 1;
}