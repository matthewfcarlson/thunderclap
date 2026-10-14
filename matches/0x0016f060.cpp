class X_16f060 {
  public:
    char pad[0x58];
    int value;
    char SetX(int value);
};
char X_16f060::SetX(int value) {
    this->value = value;
    return 1;
}
