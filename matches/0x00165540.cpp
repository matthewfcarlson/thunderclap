class X {
  public:
    char c;
    char pad[11];
    char mValue;
    char Fn(char c);
};

char X::Fn(char c) {
    mValue = c;
    return 1;
}
