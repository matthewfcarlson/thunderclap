class O_61ef0 {
  public:
    char pad[0x30];
    int value;
    char Set(int x);
};
char O_61ef0::Set(int x) {
    value = x;
    return 1;
}
