class O {
  public:
    char Pad[0x3c];
    int m3c;
    char Set(int v);
};
char O::Set(int v) {
    m3c = v;
    return 1;
}
