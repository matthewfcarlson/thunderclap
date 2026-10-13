class O {
  public:
    char Pad[0x24];
    int m24;
    char Set(int v);
};

char O::Set(int v) {
    m24 = v;
    return 1;
}
