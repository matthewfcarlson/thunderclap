struct X {
    char pad[0x18];
    int value;
};
class C {
  public:
    char pad[0x90];
    X* p;
    int f();
};
int C::f() {
    return p->value;
}