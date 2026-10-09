class C {
    char pad[0xd88];
    int value;

  public:
    void f();
};
void C::f() {
    value = 0;
}