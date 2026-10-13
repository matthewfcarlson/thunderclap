class O {
  public:
    char pad[0xc];
    int m;
    char Set(int x);
};
char O::Set(int x) {
    m = x;
    return 1;
}
