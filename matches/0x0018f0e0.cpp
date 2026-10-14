class O {
  public:
    char pad[0x68];
    int m;
    char Set(int value);
};
char O::Set(int value) {
    m = value;
    return 1;
}