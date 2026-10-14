class X_10c270 {
  public:
    char pad[0x10];
    unsigned char mX;
    unsigned char SetX(unsigned char x);
};
unsigned char X_10c270::SetX(unsigned char x) {
    mX = x;
    return 1;
}
