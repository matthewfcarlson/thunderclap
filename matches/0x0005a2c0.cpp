class Target_5a2c0 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
char Target_5a2c0::Set(int x) {
    value = x;
    return 1;
}
