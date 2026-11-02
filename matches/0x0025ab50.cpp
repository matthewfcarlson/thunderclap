struct Obj {
    void call(int, int, int, int);
};
struct Holder {
    Obj* volatile obj;
};
extern "C" void FUN_0025ab50(Holder* a, int b) {
    Obj* o = a->obj;
    o->call(b, 4, 1, 1);
}