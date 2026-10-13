class O {
  public:
    char pad[0xc];
    int m;
    char Set(int);
};

char O::Set(int x) {
    m = x;
    return 1;
}
