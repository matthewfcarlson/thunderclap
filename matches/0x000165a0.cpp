typedef unsigned int u32_165a0;
struct A_165a0 {
    A_165a0* f2();
    void f3(int);
    void f4(u32_165a0);
};
struct X_165a0 {
    A_165a0* f1();
};
struct CInvincibleAction {
    char pad[0x1c];
    X_165a0* mAt1c;
    u32_165a0 mAt20;
    void vfunc_4();
};
void CInvincibleAction::vfunc_4() {
    A_165a0* a = mAt1c->f1();
    A_165a0* b = a->f2();
    b->f3(0);
    b->f4(mAt20);
}