struct Obj {
    char pad[12];
    int type;
};
struct Callee {
    void f(Obj*);
};
struct Host {
    char pad[8];
    Callee* sub;
};
int __stdcall target(Host* a, Obj* b) {
    if (b->type == 5)
        a->sub->f(b);
    return 1;
}