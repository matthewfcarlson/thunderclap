class X_192d00 {
  public:
    char m[0xf0];
    char Fn(char v);
};

char X_192d00::Fn(char v) {
    m[0xf0] = v;
    return 1;
}
