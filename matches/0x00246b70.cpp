struct Obj_246b70 {
    char pad[0x20];
    int a;
    int b;
};

bool FUN_00246b70(Obj_246b70* p, int* out) {
    *out = p->b - p->a;
    return true;
}