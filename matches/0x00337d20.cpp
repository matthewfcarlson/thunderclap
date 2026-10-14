extern int vtable_337d20;
struct X_337d20 {
    void* v;
    int a;
    int b;
    int c;
    X_337d20(int p, int q);
};
X_337d20::X_337d20(int p, int q) {
    v = &vtable_337d20;
    a = p;
    b = q;
    c = p;
}