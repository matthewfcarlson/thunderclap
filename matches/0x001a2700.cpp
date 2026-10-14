class X {
  public:
    char pad[0xc9];
    char value;
    X() {}
    char Fn(char b);
};

char X::Fn(char b) {
    value = b;
    return 1;
}
