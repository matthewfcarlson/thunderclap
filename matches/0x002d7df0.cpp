struct Obj {
    char pad[0x38];
    int field38;
    char rest[0x214 - 0x3c];
    int field214;
};
void F1(Obj*, Obj*, Obj*);
void F2(Obj*, int);
void F3(Obj*, int);
void FUN_002d7df0(Obj** a, Obj** b, Obj** c) {
    Obj* x = 0;
    Obj* y = 0;
    Obj* z = 0;
    if (a)
        x = *a;
    if (b)
        y = *b;
    if (c)
        z = *c;
    int q = x->field214;
    F1(x, y, z);
    if (y) {
        F2(x, y->field38);
        F3(y, q);
        *b = 0;
    }
    if (z) {
        F2(x, z->field38);
        F3(z, q);
        *c = 0;
    }
    F3(x, q);
    *a = 0;
}
