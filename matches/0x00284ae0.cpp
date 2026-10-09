class C {
    char pad[0x10];

  public:
    unsigned char f();
};
unsigned char C::f() {
    return pad[0x10];
}