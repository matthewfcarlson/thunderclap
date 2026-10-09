class A {
    char pad[0x1d0];

  public:
    void Set(unsigned char x);
};
void A::Set(unsigned char x) {
    pad[0x1d0] = x;
}