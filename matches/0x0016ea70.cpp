class O {
  public:
    char pad[0x20];
    int m20;
    char Fn(int x);
};

char O::Fn(int x) {
    m20 = x;
    return 1;
}
