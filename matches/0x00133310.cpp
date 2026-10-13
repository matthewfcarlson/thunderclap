class X {
  public:
    char pad[0x30];
    int m30;
    char Fn(int v);
};

char X::Fn(int v) {
    m30 = v;
    return 1;
}
