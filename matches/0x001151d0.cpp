class O_1151d0 {
  public:
    char Pad[0x24];
    int m24;
    char Set(int v);
};

char O_1151d0::Set(int v) {
    m24 = v;
    return 1;
}
