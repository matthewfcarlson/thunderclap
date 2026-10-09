struct Manager {
    void f(void* g, void* b, int v);
};
struct Global {
    char pad[8];
    Manager* manager;
};
extern Global* g_4dd700;
struct H1 {
    void* f();
};
struct H2 {
    void* f();
};
struct X {
    char pad[0x14];
    int value;
};
struct CCameraHintAction {
    char pad[0x1c];
    H1* m1c;
    X* m20;
    bool vfunc_8(int);
};
bool CCameraHintAction::vfunc_8(int) {
    void* b = ((H2*)m1c->f())->f();
    g_4dd700->manager->f(g_4dd700, b, m20->value);
    return true;
}
