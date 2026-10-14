class O {
  public:
    char pad[0xa0];
    int value;
    char Set(int x);
};
char O::Set(int x) {
    value = x;
    return 1;
}