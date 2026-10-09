class C {
    char pad[0xb6];

  public:
    unsigned char field;
    unsigned char f();
};
unsigned char C::f() {
    return field;
}