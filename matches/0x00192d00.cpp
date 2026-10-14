class X {
  public:
    char m[0xf0];
    char Fn(char v);
};

char X::Fn(char v) {
    m[0xf0] = v;
    return 1;
}
