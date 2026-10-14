class X_139e60 {
  public:
    char pad[0x3d];
    int m40;
    char Set(int v);
};

char X_139e60::Set(int v) {
    m40 = v;
    return 1;
}
