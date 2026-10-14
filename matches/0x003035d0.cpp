struct E_3035d0 {
    int d[17];
    void Assign(E_3035d0* src);
};
extern void __cdecl FUN_003032d0(E_3035d0* first, int hole, int len, E_3035d0 v);
void __cdecl FUN_003035d0(E_3035d0* first, E_3035d0* last) {
    E_3035d0 v = last[-1];
    last[-1].Assign(first);
    FUN_003032d0(first, 0, (last - 1) - first, v);
}
