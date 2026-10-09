struct B {
    unsigned int x[0x43];
};
class C {
  public:
    char pad[0xc];
    B b;
    void Copy(B* dst);
};
void C::Copy(B* dst) {
    *dst = b;
}