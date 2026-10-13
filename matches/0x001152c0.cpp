class C {
  public:
    char pad[0x14];
    int m14;
    char Fn(int x);
};

char C::Fn(int x) {
    m14 = x;
    return 1;
}
