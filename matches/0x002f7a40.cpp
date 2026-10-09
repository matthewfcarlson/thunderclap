struct Y {
    void m(int);
};
struct X {
    char pad[0x74];
    Y* y;
};
class C {
  public:
    char pad[0xfc];
    X* field;
    void target();
};
void C::target() {
    field->y->m(1);
}
