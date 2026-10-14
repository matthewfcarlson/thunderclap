class X {
  public:
    char m[0xa8];
    char F(char c);
};
char X::F(char c) {
    m[0xa8] = c;
    return 1;
}
