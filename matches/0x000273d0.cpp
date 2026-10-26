struct Obj {
    char pad[0x1d14];
    int value;
};
struct X {
    Obj* get(unsigned a, unsigned b);
    Obj* FUN_00024280(unsigned __int64 key);
};
extern "C" unsigned __int64 __cdecl source(unsigned, unsigned, unsigned);
Obj* X::get(unsigned a, unsigned b) {
    unsigned __int64 n = source(a, 0, 0);
    Obj* p = FUN_00024280(n);
    if (p)
        p->value = b;
    return p;
}
