struct Obj {
    char pad[0x18];
    int a;
    int b;
};
int __cdecl FUN_00220530(Obj* p) {
    return p->b = p->a;
}