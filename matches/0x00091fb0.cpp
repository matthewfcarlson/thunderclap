class A {
    char pad[0x2c];

  public:
    unsigned char f();
};
unsigned char A::f() {
    return pad[0x2c];
}