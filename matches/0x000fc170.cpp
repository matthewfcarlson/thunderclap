struct X_fc170 {
    void A(int);
    void B(int);
    void C();
};
extern X_fc170* g4e0a60;
extern X_fc170* g4e0a64;
extern "C" void __cdecl FUN_000fc170(int param_1) {
    g4e0a64->A(0);
    g4e0a60->B(param_1);
    g4e0a64->C();
}