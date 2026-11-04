class X_10c230 {
  public:
    char pad[0x14];
    int m;
    char SetValue_0010c230(int x);
};

char X_10c230::SetValue_0010c230(int x) {
    m = x;
    return 1;
}
