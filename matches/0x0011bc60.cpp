class X_11bc60 {
  public:
    char pad[0x20];
    int m;
    char Set(int v);
};

char X_11bc60::Set(int v) {
    m = v;
    return 1;
}
