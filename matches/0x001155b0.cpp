class X {
  public:
    char pad[0x18];
    int m18;
    char Fn(int arg);
};
char X::Fn(int arg) {
    m18 = arg;
    return 1;
}
