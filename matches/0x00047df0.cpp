class X {
  public:
    char Fn(int a);
    char pad[16];
    int m10;
};
char X::Fn(int a) {
    m10 = a;
    return 1;
}