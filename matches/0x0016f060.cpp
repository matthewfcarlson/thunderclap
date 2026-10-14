class X {
  public:
    char pad[0x58];
    int value;
    char SetX(int value);
};
char X::SetX(int value) {
    this->value = value;
    return 1;
}
