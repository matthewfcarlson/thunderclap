struct Pair {
    int a, b;
    inline void assign(const Pair& x) {
        a = x.a;
        b = x.b;
    }
};
struct Buffer {
    char pad[8];
    Pair* p;
};
void __cdecl FUN_00212cb0(Buffer* src, Buffer* dst, int n) {
    if (src == dst)
        return;
    src->p -= n;
    for (int i = 0; i < n; ++i) {
        dst->p->assign(src->p[i]);
        ++dst->p;
    }
}