class O_16f7b0 {
  public:
    char Pad[0x3c];
    int m3c;
    char Set(int v);
};
char O_16f7b0::Set(int v) {
    m3c = v;
    return 1;
}
