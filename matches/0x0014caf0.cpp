class O {
  public:
    char Set(int x);
    char pad[0xc];
    int m1c;
};

char O::Set(int x) {
    m1c = x;
    return 1;
}