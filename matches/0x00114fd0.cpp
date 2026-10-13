class X {
  public:
    char pad[0xd];
    char m;
    char Func(char arg);
};

char X::Func(char arg) {
    m = arg;
    return 1;
}
