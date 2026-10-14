class X_14cc60 {
  public:
    char pad[0x3c];
    int m3c;
    char Set(int v);
};

char X_14cc60::Set(int v) {
    m3c = v;
    return 1;
}
