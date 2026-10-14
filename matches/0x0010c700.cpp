class O_10c700 {
  public:
    char Set(int v);
    char pad[0x24];
    int m24;
};
char O_10c700::Set(int v) {
    m24 = v;
    return 1;
}
