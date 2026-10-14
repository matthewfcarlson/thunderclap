class X_14c7c0 {
  public:
    char pad[0x14];
    char mX;
    char SetX(char value);
};

char X_14c7c0::SetX(char value) {
    mX = value;
    return 1;
}
