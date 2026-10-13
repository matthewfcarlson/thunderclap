class C {
  public:
    char pad[0x38];
    char m38;
    unsigned char Fn(unsigned char x);
};
unsigned char C::Fn(unsigned char x) {
    m38 = x;
    return 1;
}
