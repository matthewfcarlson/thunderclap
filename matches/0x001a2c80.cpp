class O {
  public:
    char pad[0x179];
    char m;
    char Set(char v);
};
char O::Set(char v) {
    m = v;
    return 1;
}