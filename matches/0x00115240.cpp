class X {
  public:
    char pad[0x1c];
    int m1c;
    char Fn(int);
};

char X::Fn(int x) {
    m1c = x;
    return 1;
}
