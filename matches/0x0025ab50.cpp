struct Obj {
    void call(int, int, int, int);
};
struct Holder {
    Obj* volatile obj;
};
void func(Holder* a, int b) {
    Obj* o = a->obj;
    o->call(b, 4, 1, 1);
}