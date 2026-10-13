class X {
  public:
    char pad[0x14];
    char mX;
    char SetX(char value);
};

char X::SetX(char value) {
    mX = value;
    return 1;
}
