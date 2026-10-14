class O_18f0e0 {
  public:
    char pad[0x68];
    int m;
    char Set(int value);
};
char O_18f0e0::Set(int value) {
    m = value;
    return 1;
}