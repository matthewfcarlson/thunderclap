struct G_292670 {
    void X();
};
struct H {
    void A();
    void B();
};
void thunk_FUN_00267090(H*);
struct T_292670 {
    int value;
    void run(H*);
};
void T_292670::run(H* arg) {
    ((G_292670*)this)->X();
    arg->A();
    if (arg) {
        arg->B();
        thunk_FUN_00267090(arg);
    }
    *(int*)this = 0;
}
