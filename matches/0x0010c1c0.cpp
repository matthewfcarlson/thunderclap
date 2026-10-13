class O {
  public:
    char pad[0x10];
    int m10;
    char Set(int x);
};
char O::Set(int x) {
    m10 = x;
    return 1;
}
