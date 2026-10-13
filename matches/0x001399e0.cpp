class X {
  public:
    char F(int a);
    char pad[0x18];
    int m18;
};

char X::F(int a) {
    m18 = a;
    return 1;
}
