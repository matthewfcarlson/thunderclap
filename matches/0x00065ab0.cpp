class C {
    char pad[0x36c];

  public:
    unsigned char value;
    unsigned char f();
};
unsigned char C::f() {
    return value;
}