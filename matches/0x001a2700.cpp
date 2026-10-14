class X_1a2700 {
  public:
    char pad[0xc9];
    char value;
    X_1a2700() {}
    char Fn(char b);
};

char X_1a2700::Fn(char b) {
    value = b;
    return 1;
}
