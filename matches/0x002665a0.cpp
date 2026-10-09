class C {
  public:
    char pad[12];
    C* field;
    void g();
    void f();
};
void C::f() {
    field->g();
}