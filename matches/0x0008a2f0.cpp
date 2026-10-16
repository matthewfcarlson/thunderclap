struct Obj {
    char pad[0xa8];
    int a;
    volatile int b;
    int c;
};
int* __fastcall FUN_0008a2f0(Obj* p) {
    if (p->a == -1)
        return 0;
    if (p->b == -1)
        return 0;
    return &p->c;
}