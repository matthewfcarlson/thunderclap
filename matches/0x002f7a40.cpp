struct Y_2f7a40 {
    void m(int);
};
struct X_2f7a40 {
    char pad[0x74];
    Y_2f7a40* y;
};
class C_2f7a40 {
  public:
    char pad[0xfc];
    X_2f7a40* field;
    void target();
};
void C_2f7a40::target() {
    field->y->m(1);
}
