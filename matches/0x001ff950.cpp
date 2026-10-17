struct Triple {
    int a, b, c;
};
struct Obj {
    int FUN_001fba60();
};
struct Factory {
    Obj* FUN_001fe080(Triple a, int b, int c, int d, int e);
    int FUN_001ff950(Triple a, int b, int c, int d, int e);
};
int Factory::FUN_001ff950(Triple a, int b, int c, int d, int e) {
    Obj* p = FUN_001fe080(a, b, c, d, e);
    if (p)
        return p->FUN_001fba60();
    return 0;
}