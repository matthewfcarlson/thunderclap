class C {
    char pad[0xb4];

  public:
    unsigned char f();
};
unsigned char C::f() {
    return pad[0xb4];
}