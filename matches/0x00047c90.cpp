class C {
  public:
    char pad[0x10];
    int m10;
    char Fn(int x);
};

char C::Fn(int x) {
    m10 = x;
    return 1;
}
