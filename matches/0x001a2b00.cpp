class X_1a2b00 {
  public:
    char m[0x149];
    char SetB(unsigned char b);
};

char X_1a2b00::SetB(unsigned char b) {
    m[0x149] = b;
    return 1;
}
