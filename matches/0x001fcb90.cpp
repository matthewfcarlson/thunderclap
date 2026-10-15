struct Obj {
    char pad[0xcd];
    unsigned char a;
    unsigned char b;
};
Obj* __stdcall Find(int);
unsigned char __stdcall FUN_001fcb90(int n) {
    Obj* p = Find(n);
    if (p && p->b && p->a)
        return 1;
    return 0;
}