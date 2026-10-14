struct Obj_1afb80 {
    char pad[12];
    int type;
};
struct Callee_1afb80 {
    void f(Obj_1afb80*);
};
struct Host_1afb80 {
    char pad[8];
    Callee_1afb80* sub;
};
int __stdcall target(Host_1afb80* a, Obj_1afb80* b) {
    if (b->type == 5)
        a->sub->f(b);
    return 1;
}