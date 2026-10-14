struct Obj {
    char pad[0x20];
    int a;
    int b;
};

bool FUN_00246b70(Obj* p, int* out) {
    *out = p->b - p->a;
    return true;
}