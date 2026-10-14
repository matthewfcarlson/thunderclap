struct Manager_17020 {
    void f(void* g, void* b, int v);
};
struct Global_17020 {
    char pad[8];
    Manager_17020* manager;
};
extern Global_17020* g_4dd700;
struct H1 {
    void* f();
};
struct H2_17020 {
    void* f();
};
struct X_17020 {
    char pad[0x14];
    int value;
};
struct CCameraHintAction {
    char pad[0x1c];
    H1* m1c;
    X_17020* m20;
    bool vfunc_8(int);
};
bool CCameraHintAction::vfunc_8(int) {
    void* b = ((H2_17020*)m1c->f())->f();
    g_4dd700->manager->f(g_4dd700, b, m20->value);
    return true;
}
