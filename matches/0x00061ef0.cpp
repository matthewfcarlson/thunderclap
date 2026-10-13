class O {
  public:
    char pad[0x30];
    int value;
    char Set(int x);
};
char O::Set(int x) {
    value = x;
    return 1;
}
