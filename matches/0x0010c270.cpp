class X {
  public:
    char pad[0x10];
    unsigned char mX;
    unsigned char SetX(unsigned char x);
};
unsigned char X::SetX(unsigned char x) {
    mX = x;
    return 1;
}
