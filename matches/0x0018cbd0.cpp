class O {
  public:
    char pad[12];
    int m;
    char Set(int x);
};
char O::Set(int x) {
    m = x;
    return 1;
}