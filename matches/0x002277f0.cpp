struct E {
    int x, y, z;
};
extern void __cdecl FUN_002273d0(E* first, int hole, int len, E v);
void __cdecl FUN_002277f0(E* first, E* last) {
    int len = last - first;
    int parent = len / 2;
    while (parent > 0) {
        parent--;
        FUN_002273d0(first, parent, len, first[parent]);
    }
}
