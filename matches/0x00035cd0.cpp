class C {
    char pad[0x300];
    int a;
    int b;

  public:
    void f();
};
void C::f() {
    a = 0;
    b = 0;
}