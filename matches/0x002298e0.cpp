struct E {
    int x, y, z;
};
extern void __cdecl FUN_00229630(E* first, int hole, int len, E v);
void __cdecl FUN_002277f0(E* first, E* last) {
    int len = last - first;
    int parent = len / 2;
    while (parent > 0) {
        parent--;
        FUN_00229630(first, parent, len, first[parent]);
    }
}
