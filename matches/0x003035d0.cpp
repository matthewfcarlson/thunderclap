struct E {
    int d[17];
    void Assign(E* src);
};
extern void __cdecl FUN_003032d0(E* first, int hole, int len, E v);
void __cdecl FUN_003035d0(E* first, E* last) {
    E v = last[-1];
    last[-1].Assign(first);
    FUN_003032d0(first, 0, (last - 1) - first, v);
}
