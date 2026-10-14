class X {
  public:
    char m[0x149];
    char SetB(unsigned char b);
};

char X::SetB(unsigned char b) {
    m[0x149] = b;
    return 1;
}
