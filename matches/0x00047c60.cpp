class X {
  public:
    char Fn(int v);
    char pad[12];
    int m;
};

char X::Fn(int v) {
    m = v;
    return 1;
}
