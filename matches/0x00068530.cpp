class O {
  public:
    char pad[16];
    int m;
    char Set(int x);
};
char O::Set(int x) {
    m = x;
    return 1;
}
