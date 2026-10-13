class X {
  public:
    char pad[12];
    int m;
    char Fn(int a);
};
char X::Fn(int a) {
    m = a;
    return 1;
}
