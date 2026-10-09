struct C {
    void f();
};
extern C* g;
void FUN_0026ed70() {
    if (g)
        g->f();
}
