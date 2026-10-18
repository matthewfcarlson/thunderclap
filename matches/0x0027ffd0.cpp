// Same code shape as 0x002665a0 (propagated; names are from that function)
class C_27ffd0 {
  public:
    char pad[12];
    C_27ffd0* field;
    void g(int, int);
    void f(int, int);
};
void C_27ffd0::f(int a0, int a1) {
    field->g(a0, a1);
}