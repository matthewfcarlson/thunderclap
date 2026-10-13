class O {
  public:
    char Set(int v);
    char pad[0x24];
    int m24;
};
char O::Set(int v) {
    m24 = v;
    return 1;
}
