struct One {
    void* f();
};
struct Two_134160 {
    void* f();
};
struct Three {
    void f(void*, int);
};
struct FallAction {
    char pad[0x20];
    One* a;
    void* b;
    void vfunc_4();
};
void FallAction::vfunc_4() {
    void* x = a->f();
    void* y = ((Two_134160*)x)->f();
    if (y)
        ((Three*)y)->f(b, 0);
}