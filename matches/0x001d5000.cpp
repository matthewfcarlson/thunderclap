struct X_1d5000 {
    char pad[0x18];
    int value;
};
class C_1d5000 {
  public:
    char pad[0x90];
    X_1d5000* p;
    int f();
};
int C_1d5000::f() {
    return p->value;
}