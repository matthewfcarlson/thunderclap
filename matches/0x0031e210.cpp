struct Obj_31e210 {
    virtual void f0();
    virtual void f1(int);
};
extern Obj_31e210* g_31e210;
void target(int x) {
    if (g_31e210)
        g_31e210->f1(x);
}