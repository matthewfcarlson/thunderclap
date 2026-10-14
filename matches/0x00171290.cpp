// Same code shape as 0x00134160 (propagated; names are from that function)
struct One {
    void* f();
};
struct Two_171290 {
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
    void* y = ((Two_171290*)x)->f();
    if (y)
        ((Three*)y)->f(b, 0);
}