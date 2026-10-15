struct Pair {
    int a, b;
};
extern "C" char __cdecl lookup(int, Pair*);
struct Obj {
    void use(int, int);
};
char __cdecl target(int x, Obj* flag) {
    Pair p;
    if (lookup(x, &p)) {
        if (flag)
            flag->use(p.a, p.b);
        return 1;
    }
    return 0;
}