struct Pair {
    int a, b;
};
extern "C" char __cdecl lookup(int, Pair*);
struct Obj {
    void use(int, int);
};
extern "C" char __cdecl FUN_00263db0(int x, Obj* flag) {
    Pair p;
    if (lookup(x, &p)) {
        if (flag)
            flag->use(p.a, p.b);
        return 1;
    }
    return 0;
}