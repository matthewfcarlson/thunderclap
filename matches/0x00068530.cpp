class O_68530 {
  public:
    char pad[16];
    int m;
    char Set(int x);
};
char O_68530::Set(int x) {
    m = x;
    return 1;
}
