struct Obj_2d7df0 {
    char pad[0x38];
    int field38;
    char rest[0x214 - 0x3c];
    int field214;
};
void F1(Obj_2d7df0*, Obj_2d7df0*, Obj_2d7df0*);
void F2(Obj_2d7df0*, int);
void F3(Obj_2d7df0*, int);
void FUN_002d7df0(Obj_2d7df0** a, Obj_2d7df0** b, Obj_2d7df0** c) {
    Obj_2d7df0* x = 0;
    Obj_2d7df0* y = 0;
    Obj_2d7df0* z = 0;
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
