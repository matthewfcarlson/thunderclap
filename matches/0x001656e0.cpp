class X {
  public:
    char Fn(int a);
    char pad[12];
    int m;
};

char X::Fn(int a) {
    m = a;
    return 1;
}
