class X {
  public:
    char pad[0xc];
    int m;
    char Fn(int v);
};

char X::Fn(int v) {
    m = v;
    return 1;
}
