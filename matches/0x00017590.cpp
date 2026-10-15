// Same code shape as 0x000165a0 (propagated; names are from that function)
typedef unsigned int u32_17590;
struct A_17590 {
    A_17590* f2();
    void f3(int);
    void f4(u32_17590);
};
struct X_17590 {
    A_17590* f1();
};
struct CUninterruptibleAction {
    char pad[0x1c];
    X_17590* mAt1c;
    u32_17590 mAt20;
    void vfunc_4();
};
void CUninterruptibleAction::vfunc_4() {
    A_17590* a = mAt1c->f1();
    A_17590* b = a->f2();
    b->f3(0);
    b->f4(mAt20);
}