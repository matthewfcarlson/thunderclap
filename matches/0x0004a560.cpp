// Same code shape as 0x0004a2d0 (propagated; names are from that function)
struct Obj_4a560 {
    char pad[0x330];
    int a;
    int b;
    int c;
};
struct Helper_4a560 {
    Obj_4a560* First();
};
struct ObjHelper_4a560 {
    Obj_4a560* Second();
};
struct CGrappleAlertStatusCondition {
    int vfunc_8(int);
};
int CGrappleAlertStatusCondition::vfunc_8(int p) {
    if (!p)
        return 0;
    Helper_4a560* h = (Helper_4a560*)p;
    Obj_4a560* x = h->First();
    x = ((ObjHelper_4a560*)x)->Second();
    if (x->b)
        return x->b;
    if (x->a)
        return x->a;
    return x->c;
}