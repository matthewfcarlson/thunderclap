struct Obj {
    char pad[0x1d14];
    int value;
};
struct X {
    Obj* get(unsigned a, unsigned b);
};
extern "C" unsigned __int64 __cdecl source(unsigned, unsigned, unsigned);
Obj* X::get(unsigned a, unsigned b) {
    unsigned __int64 n = source(a, 0, 0);
    Obj* p = get((unsigned)n, (unsigned)(n >> 32));
    if (p)
        p->value = b;
    return p;
}