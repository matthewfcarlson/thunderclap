class O {
  public:
    char m[0xe9];
    char Fn(char x);
};

char O::Fn(char x) {
    m[0xe9] = x;
    return 1;
}
