class X {
  public:
    char pad[0x6c];
    int m;
    char Fn(int a);
};

char X::Fn(int a) {
    m = a;
    return 1;
}
