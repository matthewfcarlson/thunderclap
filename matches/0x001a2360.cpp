class C {
  public:
    char m[0x58];
    char f(unsigned char x);
};
char C::f(unsigned char x) {
    m[0x58] = x;
    return 1;
}