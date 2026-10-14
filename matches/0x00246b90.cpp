struct O_246b90 {
    char pad[0x20];
    int a;
    int b;
};
char __cdecl FUN_00246b90(O_246b90* p, int x) {
    p->b = p->a + x;
    return 1;
}
