class X {
  public:
    char f(char v);
    char m[0x1e];
};

char X::f(char v) {
    m[0x1e] = v;
    return 1;
}
