struct X { void A(int); void B(int); void C(); };
extern X *g4e0a60;
extern X *g4e0a64;
extern "C" void __cdecl target(int param_1) {
    g4e0a64->A(0);
    g4e0a60->B(param_1);
    g4e0a64->C();
}